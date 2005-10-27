#ifndef GUARD_SNIPPETTREEVIEW_H_INCLUDED
#define GUARD_SNIPPETTREEVIEW_H_INCLUDED 1

#include "FowardDeclarations.h"
#include <gtkmm/treemodelcolumn.h>
#include <gtkmm/treeiter.h>
#include <gtkmm/treestore.h>
#include "types.h"

class SnippetTreeView
{
public:
    explicit SnippetTreeView( Glib::RefPtr<Gnome::Glade::Xml> xmlref );
    ~SnippetTreeView();
    void AddLanguage( Glib::ustring const & language );
    void AddCategory( Glib::ustring const & language , Glib::ustring const & category );
    void AddSnippet ( Glib::ustring const & language , Glib::ustring const & category , Glib::ustring const & title , uint64_t id );
    sigc::slot<void,uint64_t> on_click_slot; 
private:
    struct ModelColumns : Gtk::TreeModel::ColumnRecord
    {
        ModelColumns();
        virtual ~ModelColumns();
        Gtk::TreeModelColumn<Glib::ustring> m_text;
        Gtk::TreeModelColumn<uint64_t> m_id;
    };  
private:
    typedef Gtk::TreeModel::iterator tree_iter;
private:
    ModelColumns m_columns;
    std::map< Glib::ustring , Gtk::TreeIter > m_language_iter_map;
    Glib::RefPtr<Gtk::TreeStore> m_storage;
    Gtk::TreeView * m_treeview;
private:
    void OnClickEvent();
    bool ExistsLanguage( Glib::ustring const & language );
    bool ExistsCategory( Glib::ustring const & language , Glib::ustring const & category );
    bool ExistsSnippet ( Glib::ustring const & language , Glib::ustring const & category , Glib::ustring const & title , uint64_t id );
    tree_iter FindCategoryIter( Glib::ustring const & language , Glib::ustring const & category );
};
#endif //GUARD_SNIPPETTREEVIEW_H_INCLUDED
