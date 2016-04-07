/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "qzyre.h"

///
//  Copy-construct to return the proper wrapped c types
QZlist::QZlist (zlist_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Create a new list container
QZlist::QZlist (QObject *qObjParent) : QObject (qObjParent)
{
    this->self = zlist_new ();
}

///
//  Destroy a list container
QZlist::~QZlist ()
{
    zlist_destroy (&self);
}

///
//  Return the item at the head of list. If the list is empty, returns NULL.
//  Leaves cursor pointing at the head item, or NULL if the list is empty.  
void * QZlist::first ()
{
    void * rv = zlist_first (self);
    return rv;
}

///
//  Return the next item. If the list is empty, returns NULL. To move to
//  the start of the list call zlist_first (). Advances the cursor.     
void * QZlist::next ()
{
    void * rv = zlist_next (self);
    return rv;
}

///
//  Return the item at the tail of list. If the list is empty, returns NULL.
//  Leaves cursor pointing at the tail item, or NULL if the list is empty.  
void * QZlist::last ()
{
    void * rv = zlist_last (self);
    return rv;
}

///
//  Return first item in the list, or null, leaves the cursor
void * QZlist::head ()
{
    void * rv = zlist_head (self);
    return rv;
}

///
//  Return last item in the list, or null, leaves the cursor
void * QZlist::tail ()
{
    void * rv = zlist_tail (self);
    return rv;
}

///
//  Return the current item of list. If the list is empty, returns NULL.     
//  Leaves cursor pointing at the current item, or NULL if the list is empty.
void * QZlist::item ()
{
    void * rv = zlist_item (self);
    return rv;
}

///
//  Append an item to the end of the list, return 0 if OK or -1 if this  
//  failed for some reason (out of memory). Note that if a duplicator has
//  been set, this method will also duplicate the item.                  
int QZlist::append (void *item)
{
    int rv = zlist_append (self, item);
    return rv;
}

///
//  Push an item to the start of the list, return 0 if OK or -1 if this  
//  failed for some reason (out of memory). Note that if a duplicator has
//  been set, this method will also duplicate the item.                  
int QZlist::push (void *item)
{
    int rv = zlist_push (self, item);
    return rv;
}

///
//  Pop the item off the start of the list, if any
void * QZlist::pop ()
{
    void * rv = zlist_pop (self);
    return rv;
}

///
//  Checks if an item already is present. Uses compare method to determine if 
//  items are equal. If the compare method is NULL the check will only compare
//  pointers. Returns true if item is present else false.                     
bool QZlist::exists (void *item)
{
    bool rv = zlist_exists (self, item);
    return rv;
}

///
//  Remove the specified item from the list if present
void QZlist::remove (void *item)
{
    zlist_remove (self, item);
    
}

///
//  Make a copy of list. If the list has autofree set, the copied list will  
//  duplicate all items, which must be strings. Otherwise, the list will hold
//  pointers back to the items in the original list. If list is null, returns
//  NULL.                                                                    
QZlist * QZlist::dup ()
{
    QZlist *rv = new QZlist (zlist_dup (self));
    return rv;
}

///
//  Purge all items from list
void QZlist::purge ()
{
    zlist_purge (self);
    
}

///
//  Return number of items in the list
size_t QZlist::size ()
{
    size_t rv = zlist_size (self);
    return rv;
}

///
//  Sort the list by ascending key value using a straight ASCII comparison.
//  The sort is not stable, so may reorder items with the same keys.       
void QZlist::sort (zlist_compare_fn compare)
{
    zlist_sort (self, compare);
    
}

///
//  Set list for automatic item destruction; item values MUST be strings. 
//  By default a list item refers to a value held elsewhere. When you set 
//  this, each time you append or push a list item, zlist will take a copy
//  of the string value. Then, when you destroy the list, it will free all
//  item values automatically. If you use any other technique to allocate 
//  list values, you must free them explicitly before destroying the list.
//  The usual technique is to pop list items and destroy them, until the  
//  list is empty.                                                        
void QZlist::autofree ()
{
    zlist_autofree (self);
    
}

///
//  Sets a compare function for this list. The function compares two items.
//  It returns an integer less than, equal to, or greater than zero if the 
//  first item is found, respectively, to be less than, to match, or be    
//  greater than the second item.                                          
//  This function is used for sorting, removal and exists checking.        
void QZlist::comparefn (zlist_compare_fn fn)
{
    zlist_comparefn (self, fn);
    
}

///
//  Set a free function for the specified list item. When the item is     
//  destroyed, the free function, if any, is called on that item.         
//  Use this when list items are dynamically allocated, to ensure that    
//  you don't have memory leaks. You can pass 'free' or NULL as a free_fn.
//  Returns the item, or NULL if there is no such item.                   
void * QZlist::freefn (void *item, zlist_free_fn fn, bool atTail)
{
    void * rv = zlist_freefn (self, item, fn, atTail);
    return rv;
}

///
//  Self test of this class.
void QZlist::test (bool verbose)
{
    zlist_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
