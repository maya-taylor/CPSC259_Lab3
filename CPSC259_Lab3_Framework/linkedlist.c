/*
 File:         linkedlist.c
 Purpose:      Implements the linked list functions whose prototypes
               are declared in the linked_list.h header file
 Author:       Maya Taylor Quinn Senych
 Student #s:   18489633 and 45034352
 CWLs:         mtaylo11 and qsenych
 Date:         October 23, 2023
 */

#define _CRT_SECURE_NO_WARNINGS

 /* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

 /*
  Returns a pointer to a new, empty linked list of struct node.
  PRE:       NULL (no pre-conditions)
  POST:      NULL (no side-effects)
  RETURN:    A pointer to a new, empty linked list of struct node (NULL)
  */
node* create_linked_list()
{
    node* empty = NULL;
    return empty;

}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane. Note that the string attributes of the newly created
 node's struct airplane must be specially copied (refer to lab 2).
 The node's next pointer doesn't point to anything
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to NULL
 */
node* create_node(airplane plane)
{
    node* name = (node*)malloc(sizeof(node));
    name->next = NULL;
    name->plane.flight_number = plane.flight_number;
    name->plane.city_destination = strdup(plane.city_destination);
    name->plane.city_origin = strdup(plane.city_origin);
    name->plane.priority = plane.priority;
    name->plane.maximum_speed_kph = plane.maximum_speed_kph;
    name->plane.cruising_altitude = plane.cruising_altitude;
    name->plane.capacity = plane.capacity;


  return name;
}

/*
 Prepends a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_mode is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 */
node* prepend_node(node* list, node* new_node)
{
    new_node->next = list;
    list = new_node;
    return(new_node);
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list. Be aware of nested allocations!
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the dynamically
            allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
node* delete_node(node* list)
{
    if (list != NULL) {
        node* temp;
        temp = list->next;
        list = temp;
        free(temp->plane.city_destination);
        free(temp->plane.city_origin);
        free(temp);
        return list;
    }
    else {
        return NULL;
    }
}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(node* list)
{
    int count = 0;
    node* temp = list;
    while (list != NULL) {
        list = list-> next;
        count++;
  }
    list = temp;
  return count;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates the
 memory containing each struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
node* delete_list(node* list)
{
    node* temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        delete_node(temp);
    }
    list = NULL;
  return list;
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer points
 to null, else prints "Link points to address xxx\n", where xxx is the pointer address
 in hexademical.
 If node_to_print is NULL, prints "The node is empty\n".
 PARAM:     node_to_print is a pointer to a (possibly null) struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about node_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_node(node* node_to_print)
{
    if(node_to_print != NULL) {
        
        printf("flight_number: %d\n", node_to_print->plane.flight_number);
        if(node_to_print->plane.city_origin != NULL) {
            printf("Link points to address %x\n", node_to_print->plane.city_origin);
            //printf("city_origin: %s\n", node_to_print->plane.city_origin);
        }
        else {
            printf("Link = NULL\n");
        }
        if (node_to_print->plane.city_destination != NULL) {
            printf("Link points to address %x\n", node_to_print->plane.city_destination);
            //printf("city_origin: %s\n", node_to_print->plane.city_origin);
        }
        else {
            printf("Link = NULL\n");
        }
        
        printf("priority: %d\n", node_to_print->plane.priority);
        printf("maxmimum_speed_kph: %d\n", node_to_print->plane.maximum_speed_kph);
        printf("cruising_altitude: %d\n", node_to_print->plane.cruising_altitude);
        printf("capacity: %d\n", node_to_print->plane.capacity);
    }
    else {
        printf("The node is empty\n");
    }

}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(node* list_to_print)
{
    node* temp = list_to_print;
    while (list_to_print != NULL) {
        print_node(list_to_print);
        list_to_print = list_to_print->next;
        
    }
    list_to_print = temp;

}

/*
 Reverses a list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
node* reverse(node* list)
{
  // Insert your code here
    node* newHead= NULL;

    while (list != NULL) {
        node* nextNode = list->next;
        newHead = prepend_node(newHead, list);
        list = nextNode;
    }
  return newHead;
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
node* remove_from_list(node* list, char* destination_city)
{
    node* current = list;
    node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->plane.city_destination, destination_city) == 0) {
            node* toRemove = current;
            current = current->next;
            free(toRemove->plane.city_destination);
            free(toRemove->plane.city_origin);
            free(toRemove);

            if (prev == NULL) 
                list = current;

            else 
                prev->next = current;
        }
        else {
            prev = current;
            current = current->next;
        }
    }

    return list;
}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
node* retrieve_nth(node* list, int ordinality)
{
    int length = get_length(list);
    int count = 1;
    node* temp = list;
    

    if (ordinality <= length) {
        while(temp != NULL) {
            if (count == ordinality) {
                return temp;
            }
            else {
                count++;
                if(temp->next != NULL)
                    temp = temp->next;
            }
        }
    }
    else {
        return NULL;
    }
  
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 ordinality.  For example, if ordinality = 1, this is a simple prepend_node
 operation.  If ordinality = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the ordinality = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the ordinality > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
      correct location
            ELSE a pointer to the unchanged list
 */
node* insert_nth(node* list, node* node_to_insert, int ordinality)
{
    int count = 0;
    int length = get_length(list);
    node* current = list;

    if (ordinality > length + 1) {
        return list;
    }

   

    if (ordinality == 1) {
        if (list == NULL) {
            list = node_to_insert;
            node_to_insert->next = NULL;
        }
        else {
            list = prepend_node(list, node_to_insert);
        }
        return list;
    }

    if (list == NULL) {
        return NULL;
    }

    if ((ordinality < length + 1) && (list != NULL)) {
        while (current->next != NULL) {
            if (count == ordinality - 2) {
                node* temp = current->next;
                current->next = node_to_insert;
                current->next->next = temp;
                return list;
            }
            else {
                count++;
                current = current->next;
            }
        }
    }

    if (ordinality == length + 1)
    {
        if (current != NULL) {
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = node_to_insert;
            current->next->next = NULL;
        }
        return list;
    }

}