#include <iostream>
#include "SnippetTreeView.h"
#include "debughelper.h"
#include "SnalpException.h"

#include <libglademm/xml.h>
#include <gtkmm/treeview.h>

//##################################################################################################################
SnippetTreeView::SnippetTreeView( GladeRef xmlref)
{
    try
    {
        xmlref->get_widget<Gtk::TreeView>("SnippetTreeview",m_treeview);       
        m_storage = Gtk::TreeStore::create(m_columns);
        m_treeview->set_model(m_storage);
        m_treeview->append_column("",m_columns.m_text);
        m_treeview->set_headers_visible(false);
        m_treeview->get_selection()->signal_changed().connect(sigc::mem_fun(*this,&SnippetTreeView::OnClickEvent));
        
    }
    catch( Gnome::Glade::XmlError & e )
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException,e.what());
    }
    catch(...)
    {
        SNALP_ERROR("Other exception unspecified caught!");
        exit(0);
    }
}
//##################################################################################################################
SnippetTreeView::ModelColumns::~ModelColumns()
{
}
//##################################################################################################################
void SnippetTreeView::AddLanguage( Glib::ustring const & language )
{
    if(!ExistsLanguage(language))
    {
        m_language_iter_map[language] = m_storage->append();
        Gtk::TreeModel::Row row = *(m_language_iter_map[language]);
        row[m_columns.m_text] = language;
        row[m_columns.m_id]   = (uint64_t)-1;
    }
}
//##################################################################################################################
void SnippetTreeView::AddCategory( Glib::ustring const & language , Glib::ustring const & category )
{

    if(m_language_iter_map.find(language) == m_language_iter_map.end())
    {
        AddLanguage(language);
    }

    Gtk::TreeModel::Row row = *(m_storage->append(m_language_iter_map[language]->children()));
    row[m_columns.m_text] = category;
    row[m_columns.m_id]   = (uint64_t)-1;   
}
//##################################################################################################################
void SnippetTreeView::AddSnippet( Glib::ustring const & language , Glib::ustring const & category , Glib::ustring const & title    , uint64_t id )
{
    if(!ExistsSnippet(language,category,title,id))
    {
        for(tree_iter b = m_language_iter_map[language]->children().begin(), e = m_language_iter_map[language]->children().end(); b != e; ++b)        
        {
            if((*b)[m_columns.m_text] == category)
            {
                Gtk::TreeModel::Row row = *(m_storage->append(b->children()));
                row[m_columns.m_text] = title;
                row[m_columns.m_id]   = id;   
            }
        }
    }
}
//##################################################################################################################
bool SnippetTreeView::ExistsLanguage( Glib::ustring const & language )
{
    return (m_language_iter_map.find(language) != m_language_iter_map.end());
}
//##################################################################################################################
bool SnippetTreeView::ExistsCategory( Glib::ustring const & language , Glib::ustring const & category )
{
    if(ExistsLanguage(language))
    {
        tree_iter iter = m_language_iter_map[language];
        tree_iter b = iter->children().begin();
        tree_iter e = iter->children().end(); 
        while(b != e)
        {
            if((*b)[m_columns.m_text] == category)
            {
                return true;
            }
            ++b;
        }
    }
    return false;
}
//##################################################################################################################
bool SnippetTreeView::ExistsSnippet ( Glib::ustring const & language , Glib::ustring const & category , Glib::ustring const & title , uint64_t id )
{
    try
    {
        tree_iter iter = FindCategoryIter(language,category);
        tree_iter b = iter->children().begin();
        tree_iter e = iter->children().end();
        while( b != e)
        {
            if((*b)[m_columns.m_text] == title && 
                (*b)[m_columns.m_id]   == id)
            {
                return true;
            }
            ++b;
        }
    }
    catch(SnalpException const &)
    {
        return false;
    }
    return false;
}
//##################################################################################################################
void SnippetTreeView::OnClickEvent()
{
    tree_iter iter = m_treeview->get_selection()->get_selected();
    if((*iter)[m_columns.m_id] != (uint64_t)-1)
    {
        on_click_slot((*iter)[m_columns.m_id]);
    }
}
//##################################################################################################################
SnippetTreeView::tree_iter SnippetTreeView::FindCategoryIter( Glib::ustring const & language , Glib::ustring const & category )
{
    if(ExistsCategory(language,category))
    {
        tree_iter iter = m_language_iter_map[language];
        tree_iter b = iter->children().begin();
        tree_iter e = iter->children().end();
        while(b != e)
        {
            if((*b)[m_columns.m_text] == category)
            {
                return b;
            }
        }
        THROW_SNALP_EXCEPTION(SnalpNotFoundException,"Category not found!");
    }
    else 
    {
        THROW_SNALP_EXCEPTION(SnalpNotFoundException,"Language not found!");
    }
  
    // Dummy against compiler warnings
    return tree_iter();
}
//##################################################################################################################
SnippetTreeView::~SnippetTreeView()
{
}
//##################################################################################################################
SnippetTreeView::ModelColumns::ModelColumns()
{
    add(m_text);
    add(m_id);
}
//##################################################################################################################
void SnippetTreeView::Clear()
{
    m_storage->clear();
    m_language_iter_map.clear();
}