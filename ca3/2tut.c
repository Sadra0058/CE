#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGNUP 0
#define LOGIN 1
#define LOGOUT 2
#define POST 3
#define LIKE 4
#define INFO 5
#define FIND_USER 6
#define DELETE 7
#define EXIT 8
#define HELP 9

typedef struct post
{
    int post_id;
    int likenum;
    char *text;
    struct post *next;
} Post;

typedef struct likedpost
{
    Post *post;
    struct likedpost *next;
} Likedpost;

typedef struct user
{
    char *username;
    char *password;
    Post *head;
    Likedpost *likedpost;
    int postnum;
    int postcount;
    struct user *next;
} User;

char *get_input(void);
char *get_command(char *input);
int int_command(char *command);
int check_input(char *input, char *command);

User *rgstr(User *head, char *input, int access);
User *login(User *head, char *input, int *access);
void logout(int *access);
void post(User *user, char *input, int access);
void Like(User *user, User *head, char *input, int access);
void info(User *user, int access);
void find_user(User *head, char *input);
void delete(User *user, char *input, int access);
void leave(User *head);
void help(void);

int main()
{
    User *head = NULL;
    int access = 0;
    char *input;
    char *command;
    int check = 1;
    User *user;

    while (1) /*Get the head of the list of users*/
    {
        printf("Please signup first!\n");
        printf("\n");
        /*Taking input and converting it to dynamic array*/
        input = get_input();
        command = get_command(input);
        check = check_input(input, command);
        if (check == 1 && int_command(command) == SIGNUP) /*check input*/
        {
            head = rgstr(head, input, access);
            break;
        }
        if (check == 0)
        {
            printf("invalid input (you can use 'help' to see another commands)!\n");
            printf("\n");
        }
        if (int_command(command) == EXIT) /*End of program*/
        {
            free(input);
            free(command);
            return 0;
        }
        if (int_command(command) == HELP) /*Show valid commands*/
            help();
        /*free memmory*/
        free(command);
        free(input);
    }

    while (1)
    {
        do
        {
            /*free memmory*/
            free(command);
            free(input);
            /*Taking input and converting it to dynamic array*/
            printf("\n");
            printf("Enter the command: \n");
            printf("\n");
            input = get_input();
            command = get_command(input);
            check = check_input(input, command);
            if (check == 0)
                printf("invalid input (you can use 'help' to see another commands)!\n");

        } while (check == 0); /*check input*/

        switch (int_command(command)) /*Execution of orders*/
        {
        case SIGNUP:
            rgstr(head, input, access);
            break;

        case LOGIN:
            user = login(head, input, &access);
            break;

        case LOGOUT:
            logout(&access);
            break;

        case POST:
            post(user, input, access);
            break;

        case LIKE:
            Like(user, head, input, access);
            break;

        case INFO:
            info(user, access);
            break;

        case DELETE:
            delete (user, input, access);
            break;

        case FIND_USER:
            find_user(head, input);
            break;

        case HELP:
            help();
            break;

        case EXIT:
            free(command);
            free(input);
            leave(head);
            return 0;
        }
    }
}
/*It checks whether this username has been used before and returns 1 if it has not been used, and returns zero otherwise*/
int repeated_user(User *head, char *input)
{
    /*get username and password from input*/
    char *username = calloc(sizeof(char), 100);
    char *password = calloc(sizeof(char), 100);
    int i = 7;
    int j = 0;
    int k = 0;
    while (input[i] != ' ')
    {
        username[j] = input[i];
        j++;
        i++;
    }
    i++;
    j++;

    while (input[i] != '\0')
    {
        password[k] = input[i];
        k++;
        i++;
    }
    k++;
    /*free the extra occupied memory*/
    username = realloc(username, sizeof(char) * (j));
    password = realloc(password, sizeof(char) * (k));

    /*check repeated username*/
    User *cur = head;
    while (cur != NULL)
    {
        if (strcmp(cur->username, username) == 0)
        {
            /*free username and password*/
            free(username);
            free(password);
            return 0;
        }
        cur = cur->next;
    }
    /*free username and password*/
    free(username);
    free(password);
    return 1;
}
/*The command converts to a number*/
int int_command(char *command)
{
    /*counver command to int*/
    if (strcmp(command, "signup") == 0)
        return SIGNUP;
    if (strcmp(command, "login") == 0)
        return LOGIN;
    if (strcmp(command, "logout") == 0)
        return LOGOUT;
    if (strcmp(command, "post") == 0)
        return POST;
    if (strcmp(command, "like") == 0)
        return LIKE;
    if (strcmp(command, "info") == 0)
        return INFO;
    if (strcmp(command, "find_user") == 0)
        return FIND_USER;
    if (strcmp(command, "delete") == 0)
        return DELETE;
    if (strcmp(command, "exit") == 0)
        return EXIT;
    if (strcmp(command, "help") == 0)
        return HELP;
}
/*It checks that the input is correct and returns one if it is correct and zero otherwise*/
int check_input(char *input, char *command)
{
    /*number of space*/
    int i = 0;
    int space = 0;

    while (input[i] != '\0')
    {
        if (input[i] == ' ' && input[i + 1] != ' ')
            space++;
        i++;
    }
    i = 0;
    /*If the command had 3 parts*/
    if ((strcmp(command, "signup") == 0 || strcmp(command, "login") == 0) || strcmp(command, "like") == 0)
    {
        if (space == 2)
        {
            while (input[i] != ' ')
                i++;
            i++;
            if (strlen(input) != (i))
            {
                while (input[i] != ' ')
                    i++;
                if ((strlen(input) != (i + 1)))
                    return 1;
            }
        }
        return 0;
    }
    i = 0;
    /*If the command was equal to the post*/
    if ((strcmp(command, "post") == 0))
    {
        if (input[4] == ' ' && (strlen(input) > 5))
            return 1;
        return 0;
    }
    /*If the command had 1 part*/
    if (strcmp(command, "logout") == 0 || strcmp(command, "info") == 0 || strcmp(command, "exit") == 0 || strcmp(command, "help") == 0)
    {
        if (strlen(input) == strlen(command))
            return 1;
        return 0;
    }
    /*If the command had 2 parts*/
    if (strcmp(command, "find_user") == 0 || strcmp(command, "delete") == 0)
    {
        if ((input[strlen(command)] == ' ') && (strlen(input) > (strlen(command) + 1)) && space == 1)
            return 1;
        return 0;
    }
    return 0;
}
/*Adds a new user to the linkedlist and returns its address*/
User *add_user(User *head)
{
    /*If head was equal to NULL create the head*/
    if (head == NULL)
    {
        head = malloc(sizeof(User));
        head->next = NULL;
        return head;
    }
    /*If not, create a link list*/
    else
    {
        User *newuser = malloc(sizeof(User));
        User *cur = head;
        User *next = cur->next;
        /*Find the last node of the linked list*/
        while (next != NULL)
        {
            cur = cur->next;
            next = next->next;
        }
        /*insert new node*/
        cur->next = newuser;
        newuser->next = NULL;
        return newuser;
    }
}
/*Stores the input from stdin into an array*/
char *get_input(void)
{
    /*Create dynamic array containing input*/
    char *input = calloc(sizeof(char), 100);
    char temp = getchar();
    int counter = 0;
    /*Insert the entry into the array until the end*/
    while (temp != '\n')
    {
        input[counter] = temp;
        temp = getchar();
        counter++;
    }
    counter++;
    /*free the extra occupied memory*/
    input = realloc(input, sizeof(char) * (counter));

    return input;
}
/*It takes the input array and extracts the command from it and stores it in an array*/
char *get_command(char *input)
{
    /*Create dynamic array containing command*/
    char *command = calloc(sizeof(char), 100);
    int counter = 0;
    /*find command from input*/
    while (input[counter] != (' ') && input[counter] != ('\0'))
    {
        command[counter] = input[counter];
        counter++;
    }
    counter++;
    /*free the extra occupied memory*/
    command = realloc(command, sizeof(char) * (counter));

    return command;
}
/*Adds a user to previous users and returns its address*/
User *rgstr(User *head, char *input, int access)
{
    if (access == 0) /*check login or not*/
    {
        if (repeated_user(head, input) == 1) /*check repited user*/
        {
            /*get username and password from input*/
            char *username = calloc(sizeof(char), 100);
            char *password = calloc(sizeof(char), 100);
            int i = 7;
            int j = 0;
            int k = 0;
            while (input[i] != ' ')
            {
                username[j] = input[i];
                j++;
                i++;
            }
            i++;
            j++;

            while (input[i] != '\0')
            {
                password[k] = input[i];
                k++;
                i++;
            }
            k++;
            /*free the extra occupied memory*/
            username = realloc(username, sizeof(char) * (j));
            password = realloc(password, sizeof(char) * (k));
            /*add new node and Fill username and password */
            User *newuser = add_user(head);
            newuser->username = username;
            newuser->password = password;
            printf("--------------------------------\n");
            printf("Account registered successfully!\n");
            printf("--------------------------------\n");
            /*Fill other information with NULL*/
            newuser->head = NULL;
            newuser->postnum = 0;
            newuser->postcount = 0;
            newuser->likedpost = NULL;
            return newuser;
        }
        else /*If username repeated*/
        {
            printf("This username already exists!\n");
            return NULL;
        }
    }

    printf("Please log out first!\n");
}
/*If the username and password were entered correctly, it will log in to the desired account*/
User *login(User *head, char *input, int *access)
{
    if ((int)*access == 0) /*check login or not*/
    {
        /*get username and password from input*/
        char *username = calloc(sizeof(char), 100);
        char *password = calloc(sizeof(char), 100);
        int i = 6;
        int j = 0;
        int k = 0;
        while (input[i] != ' ')
        {
            username[j] = input[i];
            j++;
            i++;
        }
        i++;
        j++;

        while (input[i] != '\0')
        {
            password[k] = input[i];
            k++;
            i++;
        }
        k++;
        /*free the extra occupied memory*/
        username = realloc(username, sizeof(char) * (j));
        password = realloc(password, sizeof(char) * (k));
        /*find the account*/
        User *cur = head;
        while (cur != NULL)
        {
            if (strcmp(cur->username, username) == 0 && strcmp(cur->password, password) == 0) /*if account found return it and free memmory*/
            {
                printf("-----------------\n");
                printf("You are logged in\n");
                printf("-----------------\n");
                free(username);
                free(password);
                *access = 1;
                return cur;
            }
            cur = cur->next;
        }
        /*if account not found free memmory*/
        free(username);
        free(password);
        printf("Account not found!\n");
    }

    else if ((int)*access == 1)
    {
        printf("Please log out first!\n");
    }
}
/*Log out of the account*/
void logout(int *access)
{
    if ((int)*access == 0) /*check login or not*/
    {
        printf("You are already logged out!\n");
    }

    else
    {
        printf("------------------\n");
        printf("You are logged out\n");
        printf("------------------\n");
        *access = 0;
    }
}
/*Adds a new post to previous posts*/
void post(User *user, char *input, int access)
{
    if (access == 1) /*check login or not*/
    {
        /*get text*/
        char *text = calloc(sizeof(char), 100);
        int i = 5;
        int j = 0;

        while (input[i] != '\0')
        {
            text[j] = input[i];
            j++;
            i++;
        }
        j++;
        /*free the extra occupied memory*/
        text = realloc(text, sizeof(char) * j);
        /*add postnum and post count*/
        user->postnum += 1;
        user->postcount += 1;
        /*Check if the user has posted yet, and if not, create the first post*/
        if (user->head == NULL)
        {
            user->head = malloc(sizeof(Post));
            user->head->next = NULL;
            user->head->text = text;
            user->head->post_id = user->postnum;
            user->head->likenum = 0;
            printf("----------\n");
            printf("Post added\n");
            printf("----------\n");
            return;
        }
        else
        {
            Post *newpost = (Post *)malloc(sizeof(Post));
            Post *cur = user->head;
            Post *next = cur->next;
            /*find the last member of linkedlist and add new post*/
            while (next != NULL)
            {
                cur = cur->next;
                next = next->next;
            }
            cur->next = newpost;
            newpost->next = NULL;
            newpost->text = text;
            newpost->post_id = user->postnum;
            newpost->likenum = 0;
            printf("----------\n");
            printf("Post added\n");
            printf("----------\n");
            return;
        }
    }
    else
        printf("Please login first!\n");
}
/*It stores the posts that the user likes*/
void liked_post(User *user, Post *post)
{
    /*Check if the user has liked a post before and if not, save the first post*/
    if (user->likedpost == NULL)
    {
        user->likedpost = (Likedpost *)malloc(sizeof(Likedpost));
        user->likedpost->post = post;
        user->likedpost->next = NULL;
        return;
    }
    else
    {
        Likedpost *newpost = (Likedpost *)malloc(sizeof(Likedpost));
        Likedpost *cur = user->likedpost;
        Likedpost *next = cur->next;
        /*find the last member of linkedlist*/
        while (next != NULL)
        {
            cur = cur->next;
            next = next->next;
        }
        /*add new member*/
        cur->next = newpost;
        newpost->post = post;
        newpost->next = NULL;
        return;
    }
}
/*Returns one if the user likes a previously liked post and zero otherwise.*/
int check_like(User *user, Post *post)
{
    /*Check if the user has liked this post or not, if he did, return zero and if not, return one*/
    Likedpost *cur = user->likedpost;
    while (cur != NULL)
    {
        if (cur->post == post)
            return 0;
        cur = cur->next;
    }
    return 1;
}
/*Adds one to the likes of the desired post*/
void Like(User *user, User *head, char *input, int access)
{
    if (access == 1) /*check login or not*/
    {
        /*get username and password from input*/
        char *username = calloc(sizeof(char), 100);
        char *ID = calloc(sizeof(char), 100);
        int i = 5;
        int j = 0;
        int k = 0;
        while (input[i] != ' ')
        {
            username[j] = input[i];
            j++;
            i++;
        }
        i++;
        j++;

        while (input[i] != '\0')
        {
            ID[k] = input[i];
            k++;
            i++;
        }
        k++;
        /*free the extra occupied memory*/
        username = realloc(username, sizeof(char) * (j));
        ID = realloc(ID, sizeof(char) * (k));

        int id = atoi(ID);
        free(ID);

        User *curuser = head;
        Post *curpost;
        /*find the user*/
        while (curuser != NULL)
        {
            curpost = curuser->head;
            if (strcmp(curuser->username, username) == 0)
            {
                if (curuser->postcount != 0) /*Check if the user has posted anything yet*/
                {
                    while (curpost != NULL)
                    {
                        /*find the post*/
                        if (curpost->post_id == id)
                        {
                            if (check_like(user, curpost) == 1) /*Check if this post has already been liked or not*/
                            {
                                curpost->likenum += 1; /*add likenum*/
                                printf("----------------\n");
                                printf("you liked a post\n");
                                printf("----------------\n");
                                liked_post(user, curpost); /*Add this post to likedposts*/
                                free(username);
                                return;
                            }
                            printf("You have already liked this post!\n");
                            free(username);
                            return;
                        }
                        curpost = curpost->next;
                    }
                    printf("Post not found!\n");
                    free(username);
                    return;
                }
                else
                {
                    printf("There are no posts for this user yet!\n");
                    free(username);
                    return;
                }
            }
            curuser = curuser->next;
        } /*If the post is not found*/
        printf("username not found!\n");
        free(username);
        return;
    }
    else
        printf("Please login first!\n");
}
/*Displays the information of the user who is logged in*/
void info(User *user, int access)
{
    if (access == 1) /*check login or not*/
    {
        /*print username and password*/
        printf("\n");
        printf("username : %s\n", user->username);
        printf("password : %s\n", user->password);
        printf("--------------------------------------------------------------\n");
        Post *cur = user->head;
        /*Print details of posts up to the last post*/
        while (cur != NULL)
        {
            printf("Post: %s | Likes: %i | Post_id: %i\n", cur->text, cur->likenum, cur->post_id);
            printf("--------------------------------------------------------------\n");
            cur = cur->next;
        }
    }
    else
    {
        printf("Please login first!\n");
    }
}
/*Displays the posts of the desired user*/
void find_user(User *head, char *input)
{
    /*get username*/
    char *username = calloc(sizeof(char), 100);
    int i = 10;
    int j = 0;
    while (input[i] != '\0')
    {
        username[j] = input[i];
        i++;
        j++;
    }
    j++;
    /*free the extra occupied memory*/
    username = realloc(username, j);

    User *curuser = head;
    Post *curpost;
    /*Find the username from the link list to reach the end*/
    while (curuser != NULL)
    {
        if (strcmp(curuser->username, username) == 0)
        {
            /*Show posts up to the last post and username*/
            curpost = curuser->head;
            printf("\n");
            printf("username : %s\n", curuser->username);
            printf("--------------------------------------------------------------\n");
            while (curpost != NULL)
            {
                printf("Post: %s | Likes: %i | Post_id: %i\n", curpost->text, curpost->likenum, curpost->post_id);
                printf("--------------------------------------------------------------\n");
                curpost = curpost->next;
            }
            /*free username*/
            free(username);
            return;
        }
        curuser = curuser->next;
    }
    printf("User not found!\n"); /*if user not found*/
    free(username);
    return;
}
/*Removes the desired post from the linked list*/
void delete(User *user, char *input, int access)
{
    if (access == 1) /*check login or not*/
    {
        /*get post id and counvert it to int*/
        char *ID = calloc(sizeof(char), 100);
        int i = 7;
        int j = 0;
        while (input[i] != '\0')
        {
            ID[j] = input[i];
            i++;
            j++;
        }
        j++;
        ID = realloc(ID, j);
        int id = atoi(ID);
        /*free the extra occupied memory*/
        free(ID);

        if (user->postcount != 0) /*Check if there is post for the user*/
        {
            Post *prev = user->head;
            Post *cur = prev->next;

            if (prev->post_id == id) /*If the id was equal to head of linkedlist*/
            {
                /*if there was NULL after head*/
                if (prev->next == NULL)
                {
                    user->head = NULL;
                    printf("------------\n");
                    printf("Post deleted\n");
                    printf("------------\n");
                    /*free post and its text*/
                    free(prev->text);
                    free(prev);
                    user->postcount -= 1;
                    return;
                }
                /*if there was NULL after head->next*/
                else if (cur->next == NULL)
                {
                    user->head = cur;
                    cur->next = NULL;
                    /*free post and its text*/
                    free(prev->text);
                    free(prev);
                    printf("------------\n");
                    printf("Post deleted\n");
                    printf("------------\n");
                    user->postcount -= 1;
                    return;
                }
                else
                {
                    cur->next = user->head->next->next;
                    user->head = cur;
                    /*free post and its text*/
                    free(prev->text);
                    free(prev);
                    printf("------------\n");
                    printf("Post deleted\n");
                    printf("------------\n");
                    user->postcount -= 1;
                    return;
                }
            }
            else /*If the id was not equal to head of linkedlist*/
            {
                while (cur != NULL)
                {
                    if (cur->post_id == id) /*find the post*/
                    {
                        if (cur->next == NULL) /*if there was NULL after the post*/
                        {
                            prev->next = NULL;
                            /*free post and its text*/
                            free(cur->text);
                            free(cur);
                            printf("------------\n");
                            printf("Post deleted\n");
                            printf("------------\n");
                            user->postcount -= 1;
                            return;
                        }

                        else
                        {
                            prev->next = cur->next;
                            /*free post and its text*/
                            free(cur->text);
                            free(cur);
                            printf("------------\n");
                            printf("Post deleted\n");
                            printf("------------\n");
                            user->postcount -= 1;
                            return;
                        }
                    }
                    prev = prev->next;
                    cur = cur->next;
                }
                /*if the post not found*/
                printf("Post not found!\n");
                return;
            }
        }
        else
        {
            printf("There are no posts for this user yet!\n");
            return;
        }
    }
    else
        printf("Please login first!\n");
    return;
}
/*free Linkedlist of each user's liked posts*/
void free_likedpost(User *user)
{
    if (user->likedpost == NULL)
        return;

    Likedpost *del;
    Likedpost *prev = user->likedpost;
    Likedpost *cur = user->likedpost->next;

    while (1)
    {
        if (cur == NULL)
        {
            free(prev);
            return;
        }
        del = prev;
        prev = prev->next;
        cur = cur->next;
        free(del);
    }
}
/*free Linkedlist of each user's posts*/
void free_post(User *user)
{
    if (user->head == NULL)
        return;

    Post *del;
    Post *prev = user->head;
    Post *cur = user->head->next;

    while (1)
    {
        if (cur == NULL)
        {
            free(prev->text);
            free(prev);
            return;
        }
        del = prev;
        prev = prev->next;
        cur = cur->next;
        free(del->text);
        free(del);
    }
}
/*free users*/
void free_user(User *head)
{
    User *prev = head;
    User *cur = head->next;
    User *del;

    while (1)
    {
        if (cur == NULL)
        {
            free_post(prev);
            free_likedpost(prev);
            free(prev->username);
            free(prev->password);
            free(prev);
            return;
        }
        else
        {
            del = prev;
            prev = prev->next;
            cur = cur->next;
            free_post(del);
            free_likedpost(del);
            free(del->username);
            free(del->password);
            free(del);
        }
    }
}
/*It releases everything and closes the program*/
void leave(User *head)
{
    free_user(head);
}
/*Displays the commands that the user can use*/
void help(void)
{
    printf("\n");
    printf("for ...\n");
    printf("signup: signup <username> <password>\n");
    printf("login: login <username> <password>\n");
    printf("logout: logout\n");
    printf("find a user: find_user <username>\n");
    printf("Create a post: post <your text>\n");
    printf("delete a post: delete <post_id>\n");
    printf("like: like <username> <post_id>\n");
    printf("exit: exit\n");
    printf("\n");
}