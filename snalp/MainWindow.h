#ifndef GUARD_MAINWINDOW_H_INCLUDED
#define GUARD_MAINWINDOW_H_INCLUDED 1

#include "FowardDeclarations.h"
#include "types.h"
#include <map>

class SnalpDialogs;

class MainWindow
{
public:
    MainWindow();
    ~MainWindow();
    static int Run( int argc , char ** argv );
private:    
    Gtk::Window * window;
    Gtk::TextView * text_view;

    GladeRef XmlRef;
    boost::shared_ptr<SnippetTreeView> snippet_tv;
    boost::shared_ptr<Database> database;
    boost::shared_ptr<SnalpSignals> signals;
    boost::shared_ptr<SnalpDialogs> dialogs;
    std::map<std::string , Gtk::Label * > DataLabels;
private:    
    void ConnectMenuSignals();
    void SetupDialogs();
    void ConnectSignals();
    void LoadFromDatabase();
    void LoadAllLanguages();
    void LoadAllCategories();
    void LoadAllSnippets();
private: 
    void AddLanguage( std::string const & language );
    void AddCategory( std::string const & category );
    void AddSnippet( std::string const & language , std::string const & category , std::string const & title , uint64_t id );
};

#endif //GUARD_MAINWINDOW_H_INCLUDED
