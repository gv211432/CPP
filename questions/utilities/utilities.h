#ifndef utilities
#define utilities

namespace total_private
{
#include "convert.h"
#include "table.h"
#include "print_arr_vec.h"
#include "convert.h"
#include "ListNode.h"
}

namespace leetcode
{

    // Used for printign Dynamic Problems in Boxes or beautiful tables
    // boxes::Boxes Box;
    // // Used to conver Vector Of Vector to Array Of Array and vice - versa
    // convert_vector Convert;
    // // Used to print vectors, arrays, vector of vectors and array of arrays
    // print_vector Print;
    // This is LeetCode ListNode struct utility
    // list_node::_List_node ListNode;

    total_private::boxes::Boxes Box;
    total_private::list_node::List_Node ListNode;
    total_private::print_vec::Print Print;
    total_private::convert_vec::Convert Convert;

}; // namespace boxes

#endif