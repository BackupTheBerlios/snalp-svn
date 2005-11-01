#include "MainWindow.h"

#include <iostream>
#include <gtkmm.h>
#include <libglademm.h>

#include "SnalpAddLanguageDialog.h"
#include "SnalpAddCategoryDialog.h"

#include "SnalpException.h"
#include "SnippetTreeView.h"
#include "SnalpSignals.h"
#include "Database.h"
#include "SnalpDialogs.h"
#include "debughelper.h"

//##################################################################################################################
MainWindow::MainWindow()
: window(0)
{
    try{
        XmlRef = Gnome::Glade::Xml::create("snalp_glade_gui/snalp.glade");
        XmlRef->get_widget<Gtk::Window>("MainWindow",window);
        snippet_tv = boost::shared_ptr<SnippetTreeView>(new SnippetTreeView(XmlRef));
        database = boost::shared_ptr<Database>(new Database);
        SetupDialogs();
        ConnectSignals();
        ConnectMenuSignals();
        LoadFromDatabase();

        //snippet_tv->AddLanguage("C++");
        //snippet_tv->AddCategory("C++","File I/O");
        //snippet_tv->AddSnippet("C++","File I/O","Reading files",1ULL);
    }
    catch( Gnome::Glade::XmlError & e )
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException,e.what());
    }
}
//##################################################################################################################
MainWindow::~MainWindow()
{
}
//##################################################################################################################
int MainWindow::Run( int argc , char ** argv )
{
    Gtk::Main main_obj(argc,argv);
    MainWindow application;
    main_obj.run(*application.window);
    return EXIT_SUCCESS;
}
//##################################################################################################################
void MainWindow::ConnectMenuSignals()
{
    try
    {
        Gtk::MenuItem * item = 0;
        XmlRef->get_widget<Gtk::MenuItem>("menu_beenden1",item);
        item->signal_activate().connect(sigc::mem_fun(*(this->window),&Gtk::Window::hide));
        XmlRef->get_widget<Gtk::MenuItem>("add_language1",item);
        item->signal_activate().connect(sigc::mem_fun(*dialogs->AddLanguageDialog,&SnalpAddLanguageDialog::Run));
        XmlRef->get_widget<Gtk::MenuItem>("add_category1",item);
        item->signal_activate().connect(sigc::mem_fun(*dialogs->AddCategoryDialog,&SnalpAddCategoryDialog::Run));
    }
    catch( Gnome::Glade::XmlError & e)
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException,e.what());
    }
}
//##################################################################################################################
void MainWindow::SetupDialogs()
{
    signals = boost::shared_ptr<SnalpSignals>(new SnalpSignals);
    dialogs = boost::shared_ptr<SnalpDialogs>(new SnalpDialogs(XmlRef,signals));    
}
//##################################################################################################################
void MainWindow::ConnectSignals()
{
    signals->AddCategorySlot  = sigc::mem_fun(*this,&MainWindow::AddCategory);
    signals->AddLanguageSlot  = sigc::mem_fun(*this,&MainWindow::AddLanguage);
}
//##################################################################################################################
void MainWindow::AddLanguage( std::string const & language )
{
    database->AddLanguage(language);
    LoadFromDatabase();
}
//##################################################################################################################
void MainWindow::AddCategory( std::string const & category )
{
    database->AddGroup(category);
    LoadFromDatabase();
}
//##################################################################################################################
void MainWindow::AddSnippet( std::string const & language , std::string const & category , std::string const & title , uint64_t id )
{
    snippet_tv->AddSnippet(Glib::locale_to_utf8(language),
                           Glib::locale_to_utf8(category),
                           Glib::locale_to_utf8(title),
                           id );
}
//##################################################################################################################
void MainWindow::LoadFromDatabase()
{
    snippet_tv->Clear();
    LoadAllLanguages();
    LoadAllCategories();
    LoadAllSnippets();
}
//##################################################################################################################
void MainWindow::LoadAllLanguages()
{
    IdToStringMap::const_iterator it  = database->GetLanguages().begin();
    IdToStringMap::const_iterator end = database->GetLanguages().end();
    while(it != end)
    {
        snippet_tv->AddLanguage(Glib::locale_to_utf8(it->second));
        ++it;
    }
}
//##################################################################################################################
void MainWindow::LoadAllCategories()
{
    IdToStringMap::const_iterator it  = database->GetGroups().begin();
    IdToStringMap::const_iterator end = database->GetGroups().end();
    IdToStringMap::const_iterator lang_it, lang_end;
    while(it != end)
    {
        lang_it  = database->GetLanguages().begin();
        lang_end = database->GetLanguages().end();
        while(lang_it != lang_end)
        {
            snippet_tv->AddCategory(lang_it->second,it->second);
            ++lang_it;
        }
        ++it;
    }
}
//##################################################################################################################
void MainWindow::LoadAllSnippets()
{
    IdToStringMap & lang_map = database->GetLanguages();
    IdToStringMap & cat_map  = database->GetGroups();
    TreeviewIdMap & tidm = database->GetAll();
    TreeviewIdMap::const_iterator lang_it = tidm.begin();
    TreeviewIdMap::const_iterator lang_end = tidm.end();
    TreeviewIdMap::mapped_type::const_iterator cat_it, cat_end;
    IdList::const_iterator topic_it, topic_end;
    while(lang_it != lang_end)
    {        
        cat_it  = lang_it->second.begin();
        cat_end = lang_it->second.end();
        while(cat_it != cat_end)
        {
            topic_it  = cat_it->second.begin();
            topic_end = cat_it->second.end();
            while( topic_it != topic_end )
            {
                AddSnippet( lang_map[lang_it->first] , cat_map[cat_it->first] , database->GetTopic(*topic_it),*topic_it );
                ++topic_it;
            }
            ++cat_it;
        }
        ++lang_it;
    }
}
//##################################################################################################################
