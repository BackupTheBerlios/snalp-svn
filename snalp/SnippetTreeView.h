#ifndef GUARD_SNIPPETTREEVIEW_H_INCLUDED
#define GUARD_SNIPPETTREEVIEW_H_INCLUDED 1

#ifdef _MSC_VER
    #pragma warning( disable :4250)
    #pragma warning( disable :4541)
    #pragma once
#endif

#include <libglademm.h>
#include <gtkmm.h>
#include "types.h"

class SnippetTreeView
{
public:
    explicit SnippetTreeView( Glib::RefPtr<Gnome::Glade::Xml> xmlref );
    ~SnippetTreeView();
    void AddLanguage( Glib::ustring const & language );
    void AddCategory( Glib::ustring const & language , Glib::ustring const & category );
    void AddSnippet ( Glib::ustring const & language , Glib::ustring const & category , Glib::ustring const & title    , uint64_t id );
private:
    struct ModelColumns : Gtk::TreeModel::ColumnRecord
    {
        ModelColumns();
        virtual ~ModelColumns();
        Gtk::TreeModelColumn<Glib::ustring> m_text;
        Gtk::TreeModelColumn<uint64_t> m_id;
    };  
    ModelColumns m_columns;
    std::map< Glib::ustring , Gtk::TreeIter > m_language_iter_map;
    Glib::RefPtr<Gtk::TreeStore> m_storage;
    Gtk::TreeView * m_treeview;
};
#endif //GUARD_SNIPPETTREEVIEW_H_INCLUDED