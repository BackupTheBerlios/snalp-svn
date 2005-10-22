#include <iostream>
#include ".\snippettreeview.h"

SnippetTreeView::SnippetTreeView( Glib::RefPtr<Gnome::Glade::Xml> xmlref)
{
    try
    {
        xmlref->get_widget<Gtk::TreeView>("SnippetTreeview",m_treeview);       
        m_storage = Gtk::TreeStore::create(m_columns);
        m_treeview->set_model(m_storage);
        m_treeview->append_column("",m_columns.m_text);
        m_treeview->set_headers_visible(false);
    }
    catch( Gnome::Glade::XmlError & e )
    {
        std::cout << e.what() << std::endl;
        system("pause");
        exit(0);
    }
    catch(...)
    {
        std::cout << "Other error" << std::endl;
        system("Pause");
        exit(0);
    }
}
SnippetTreeView::ModelColumns::~ModelColumns()
{
}
void SnippetTreeView::AddLanguage( Glib::ustring const & language )
{
    if(m_language_iter_map.find(language) == m_language_iter_map.end())
    {
        m_language_iter_map[language] = m_storage->append();
        Gtk::TreeModel::Row row = *(m_language_iter_map[language]);
        row[m_columns.m_text] = language;
        row[m_columns.m_id]   = (uint64_t)-1;
    }
}
void SnippetTreeView::AddCategory( Glib::ustring const & language , Glib::ustring const & category )
{
}
void SnippetTreeView::AddSnippet( Glib::ustring const & language , Glib::ustring const & category , Glib::ustring const & title    , uint64_t id )
{
}
SnippetTreeView::~SnippetTreeView()
{
}
SnippetTreeView::ModelColumns::ModelColumns()
{
    add(m_text);
    add(m_id);
}
