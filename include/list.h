/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

    #include <stdlib.h>
    #include <sys/queue.h>
    #include <stdbool.h>

    /**
    * @brief A macro to define a print callback
    *
    * @param print_func void your_print(what to print)
    */
    #define PRINT_CALLBACK void (*print_func)(void *)

    /**
    * @brief A macro to define a free callback
    *
    * @param free_func void your_free(void *data)
    */
    #define FREE_CALLBACK void (*free_func)(void *)

    /**
    * @brief A macro to define a compare callback
    *
    * @param cmp_func bool your_cmp(void *data, void *element)
    */
    #define CMP_CALLBACK bool (*cmp_func)(void *, void *)

    /**
    * @brief A node of the linked list
    *
    */
    struct linked_list_node {
        void *data;
        TAILQ_ENTRY(linked_list_node) nodes;
    };

    /**
    * @brief typedef for struct linked_list_node
    *
    */
    typedef struct linked_list_node linked_list_node_t;

    /**
    * @brief A linked list structure (head of the list)
    *
    */
    struct linked_list {
        TAILQ_HEAD(list_head, linked_list_node) head;
    };

    /**
    * @brief typedef for struct linked_list
    *
    */
    typedef struct linked_list linked_list_t;

    /**
    * @brief Init a linked list
    *
    * @return linked_list_t*
    */
    linked_list_t* ll_init_linked_list(void);

    /**
    * @brief add a node at the end of the list
    *
    * @param list linked_list_t*
    * @param void *data (data is a pointer to the data you want to store)
    *
    * @return bool (1 if success, 0 if error)
    */
    bool ll_add_node_end(linked_list_t *list, void *data);

    /**
    * @brief add a node at the head of the list
    *
    * @param list linked_list_t*
    * @param data (data is a pointer to the data you want to store)
    *
    * @return bool (1 if success, 0 if error)
    */
    bool ll_add_node_head(linked_list_t *list, void *data);

    /**
    * @brief remove a node from the list
    *
    * @param list linked_list_t*
    * @param node struct linked_list_node*
    */
    void ll_remove_node(linked_list_t *list, struct linked_list_node *node);

    /**
    * @brief print the list with a function
    *
    * @param list linked_list_t*
    * @param print_func void your_print(what to print)
    */
    void ll_print_list(linked_list_t *list, PRINT_CALLBACK);

    /**
    * @brief free the list with a function for the elements in date
    *
    * @param list linked_list_t*
    * @param free_func void your_free(void *data)
    */
    void ll_free_list(linked_list_t *list, FREE_CALLBACK);

    /**
    * @brief check if an element is present in the list
    *
    * @param list linked_list_t*
    * @param element the element to check
    * @param cmp_func bool your_cmp(void *data, void *element)
    * @return true / false
    */
    bool ll_is_element_present(linked_list_t *list, void *element,
    CMP_CALLBACK);

    /**
    * @brief check if an element is present in the list and remove
    * it if it is
    *
    * @param list linked_list_t*
    * @param element the element to check and remove
    * @return true / false
    */
    bool ll_is_element_present_remove(linked_list_t *list, void *element,
    CMP_CALLBACK);

    /**
    * @brief get the length of the list
    *
    * @param list linked_list_t*
    * @return int
    */
    int ll_get_list_length(linked_list_t *list);

    /**
    * @brief reverse the list
    *
    * @param list linked_list_t*
    */
    void ll_reverse_list(linked_list_t *list);

    /**
    * @brief Get the nb elements object
    *
    * @param list linked_list_t*
    * @param data void*
    * @return int - the number of elements in the list
    */
    int ll_get_nb_elements(linked_list_t *list, void *data, CMP_CALLBACK);

    /**
    * @brief Remove all other occurences of the element in the list
    *
    * @param list linked_list_t*
    * @param data void* - the element to save
    * @return int - the number of elements removed
    */
    int ll_remove_all_other_occurences(linked_list_t *list, void *data,
    CMP_CALLBACK);

    /**
    * @brief Pop the first node of the list
    *
    * @param list linked_list_t*
    * @return void* - the data of the node
    */
    void *ll_pop_node(linked_list_t *list);

#endif /* !LIST_H_ */
