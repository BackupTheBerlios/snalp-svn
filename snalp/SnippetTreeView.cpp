#include <iostream>
#include ".\snippettreeview.h"

SnippetTreeView::SnippetTreeView( Glib::RefPtr<Gnome::Glade::Xml> xmlref)
{
    try
    {
        xmlref->get_widget<Gtk::TreeView>("SnippetTreeview",m_treeview);       
        m_treeview->set_model(m_storage);
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

SnippetTreeView::~SnippetTreeView()
{
}
SnippetTreeView::ModelColumns::ModelColumns()
{
    add(m_text);
}
SnippetTreeView::ModelColumns::~ModelColumns()
{
}
