#ifndef GUARD_FORWARDDECLARATIONS_H_INCLUDED
#define GUARD_FORWARDDECLARATIONS_H_INCLUDED 1

#ifdef _MSC_VER
    #pragma warning( disable :4250)
    #pragma warning( disable :4541)
    #pragma once
#endif

#include <glibmm/ustring.h>

namespace Gnome
{
    namespace Glade
    {
        class Xml;
    }
}
namespace Gtk
{
    class Window;
    class Label;
    class TextView;
    class TreeStore;
    class TreeView;
}

class SnippetTreeView;

#endif
