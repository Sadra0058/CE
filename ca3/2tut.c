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
void leave(User *head, int *leave);
void help(void);

int main()
{
    User *head = NULL;
    int access = 0;
    int exit = 1;
    char *input;
    char *command;
    int check;
    User *user;
    while (exit == 1)
    {
        do
        {
            printf("Please signup first!\n");
            printf("\n");
            input = get_input();
            command = get_command(input);
            check = check_input(input, command);
            if (int_command(command) == HELP)
                help();
            if (check == 0)
            {
                printf("invalid input (you can use 'help' to see another commands)!\n");
                printf("\n");
            }
        } while ((strcmp(command, "signup") != 0 && strcmp(command, "exit") != 0) || check == 0);
        if (int_command(command) == EXIT)
        {
            exit = 0;
            break;
        }
        head = rgstr(head, input, access);
        break;
    }

    while (exit == 1)
    {
        do
        {
            printf("\n");
            printf("Enter the command: \n");
            printf("\n");
            input = get_input();
            command = get_command(input);
            check = check_input(input, command);
            if (check == 0)
            {
                printf("invalid input (you can use 'help' to see another commands)!\n");
            }
        } while (check == 0);

        switch (int_command(command))
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

        case FIND_USER:
            find_user(head, input);
            break;

        case DELETE:
            delete (user, input, access);
            break;

        case EXIT:
            leave(head, &exit);
            break;

        case HELP:
            help();
            break;
        }
    }
}

void user_pass(char *input, char *user, char *password)
{

    int i = 0;
    int j = 0;
    int k = 0;
    while (input[i] != ' ')
        i++;
    i++;

    while (input[i] != ' ')
    {
        user[j] = input[i];
        j++;
        i++;
    }

    j++;
    i++;
    while (input[i] != '\0')
    {
        password[k] = input[i];
        k++;
        i++;
    }
    k++;

    realloc(user, sizeof(char) * (j));
    realloc(password, sizeof(char) * (k));
}

int repited_user(User *head, char *input)
{
    char *user = calloc(sizeof(char), 100);
    char *password = calloc(sizeof(char), 100);
    user_pass(input, user, password);
    User *cur = head;
    while (cur != NULL)
    {
        if (strcmp(cur->username, user) == 0)
        {
            free(user);
            free(password);
            return 0;
        }
        cur = cur->next;
    }
    return 1;
}

int int_command(char *command)
{
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

int check_input(char *input, char *command)
{
        int i = 0;
        int space = 0;

        while (input[i] != '\0')
        {
            if (input[i] == ' ' && input[i + 1] != ' ')
                space++;
            i++;
        }
        i = 0;

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

        if ((strcmp(command, "post") == 0))
        {
            if (input[4] == ' ' && (strlen(input) > 5))
                return 1;
            return 0;
        }

        if (strcmp(command, "logout") == 0 || strcmp(command, "info") == 0 || strcmp(command, "exit") == 0 || strcmp(command, "help") == 0)
        {
            if (strlen(input) == strlen(command))
                return 1;
            return 0;
        }
        if (strcmp(command, "find_user") == 0 || strcmp(command, "delete") == 0)
        {
            if ((input[strlen(command)] == ' ') && (strlen(input) > (strlen(command) + 1)) && space == 1)
                return 1;
            return 0;
        }
    return 0;
}

User *add_user(User *head)
{

    if (head == NULL)
    {
        head = (User *)malloc(sizeof(User));
        head->next = NULL;
        return head;
    }
    else
    {
        User *newuser = (User *)malloc(sizeof(User));
        User *cur = head;
        User *next = cur->next;
        while (next != NULL)
        {
            cur = cur->next;
            next = next->next;
        }
        cur->next = newuser;
        newuser->next = NULL;
        return newuser;
    }
}

char *get_input(void)
{
    char *input = calloc(sizeof(char), 100);
    char temp = getchar();
    int counter = 0;
    while (temp != '\n')
    {
        input[counter] = temp;
        temp = getchar();
        counter++;
    }
    counter++;
    realloc(input, sizeof(char) * (counter));

    return input;
}

char *get_command(char *input)
{
    char *command = calloc(sizeof(char), 100);
    int counter = 0;
    int lenght = strlen(input);
    for (int i = 0; i < lenght; i++)
    {
        if (input[i] == ' ')
            break;
        else if (i == lenght - 1)
        {
            return input;
        }
    }

    while (input[counter] != (' '))
    {
        command[counter] = input[counter];
        counter++;
    }

    counter++;
    realloc(command, sizeof(char) * (counter));

    return command;
}

User *rgstr(User *head, char *input, int access)
{
    if (access == 0)
    {
        if (repited_user(head, input) == 1)
        {
            char *username = calloc(sizeof(char), 20);
            char *password = calloc(sizeof(char), 20);
            user_pass(input, username, password);
            User *newuser = add_user(head);
            newuser->username = username;
            newuser->password = password;
            printf("--------------------------------\n");
            printf("Account registered successfully!\n");
            printf("--------------------------------\n");
            newuser->head = NULL;
            newuser->postnum = 0;
            newuser->postcount = 0;
            newuser->likedpost = NULL;
            return newuser;
        }
        else
        {
            printf("This username already exists!\n");
            return NULL;
        }
    }

    printf("Please log out first!\n");
}

User *login(User *head, char *input, int *access)
{
    if ((int)*access == 0)
    {
        char *username = calloc(sizeof(char), 20);
        char *password = calloc(sizeof(char), 20);
        user_pass(input, username, password);
        User *cur = head;
        while (cur != NULL)
        {
            if (strcmp(cur->username, username) == 0 && strcmp(cur->password, password) == 0)
            {
                printf("-----------------\n");
                printf("You are logged in\n");
                printf("-----------------\n");
                *access = 1;
                return cur;
            }
            cur = cur->next;
        }
        free(username);
        free(password);
        printf("Account not found!\n");
    }
    else if ((int)*access == 1)
    {
        printf("Please log out first!\n");
    }
}

void logout(int *access)
{
    if ((int)*access == 0)
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

void post(User *user, char *input, int access)
{
    if (access == 1)
    {

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
        realloc(text, sizeof(input) * j);

        user->postnum += 1;
        user->postcount += 1;
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

void liked_post(User *user, Post *post)
{
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
        while (next != NULL)
        {
            cur = cur->next;
            next = next->next;
        }
        cur->next = newpost;
        newpost->post = post;
        newpost->next = NULL;
        return;
    }
}

int check_like(User *user, Post *post)
{
    Likedpost *cur = user->likedpost;
    while (cur != NULL)
    {
        if (cur->post == post)
            return 0;
        cur = cur->next;
    }
    return 1;
}

void Like(User *user, User *head, char *input, int access)
{
    if (access == 1)
    {
        char *ID = calloc(sizeof(char), 100);
        char *username = calloc(sizeof(char), 100);
        user_pass(input, username, ID);
        int id = atoi(ID);
        free(ID);
        User *curuser = head;
        Post *curpost;

        while (curuser != NULL)
        {
            curpost = curuser->head;
            if (strcmp(curuser->username, username) == 0)
            {
                if (curuser->postcount != 0)
                {
                    while (curpost != NULL)
                    {
                        if (curpost->post_id == id)
                        {
                            if (check_like(user, curpost) == 1)
                            {
                                curpost->likenum += 1;
                                printf("----------------\n");
                                printf("you liked a post\n");
                                printf("----------------\n");
                                liked_post(user, curpost);
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
        }
        printf("username not found!\n");
        free(username);
        return;
    }
    else
        printf("Please login first!\n");
}

void info(User *user, int access)
{
    if (access == 1)
    {
        printf("\n");
        printf("username : %s\n", user->username);
        printf("password : %s\n", user->password);
        printf("--------------------------------------------------------------\n");
        Post *cur = user->head;
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

void find_user(User *head, char *input)
{
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
    realloc(username, j);

    User *curuser = head;
    Post *curpost;
    while (curuser != NULL)
    {
        if (strcmp(curuser->username, username) == 0)
        {
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
            free(username);
            return;
        }
        curuser = curuser->next;
    }
    printf("User not found!\n");
    free(username);
    return;
}

void delete(User *user, char *input, int access)
{
    if (access == 1)
    {
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
        realloc(ID, j);
        int id = atoi(ID);
        free(ID);
        if (user->postcount != 0)
        {
            Post *prev = user->head;
            Post *cur = prev->next;

            if (prev->post_id == id)
            {
                if (prev->next == NULL)
                {
                    user->head = NULL;
                    printf("------------\n");
                    printf("Post deleted\n");
                    printf("------------\n");
                    free(prev);
                    user->postcount -= 1;
                    return;
                }
                else if (cur->next == NULL)
                {
                    user->head = cur;
                    cur->next = NULL;
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
                    free(prev);
                    printf("------------\n");
                    printf("Post deleted\n");
                    printf("------------\n");
                    user->postcount -= 1;
                    return;
                }
            }
            else
            {
                while (cur != NULL)
                {
                    if (cur->post_id == id)
                    {
                        if (cur->next == NULL)
                        {
                            prev->next = NULL;
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

void free_post(User *user)
{
    if (user->head == NULL)
    {
        return;
    }

    Post *del;
    Post *prev = user->head;
    Post *cur = user->head->next;

    while (1)
    {
        if (cur == NULL)
        {
            free(prev->text);
            free(prev);
            break;
        }
        del = prev;
        prev = prev->next;
        cur = cur->next;
        free(del->text);
        free(del);
    }
    return;
}

void free_likedpost(User *user)
{
    if (user->likedpost == NULL)
    {
        return;
    }

    Likedpost *del;
    Likedpost *prev = user->likedpost;
    Likedpost *cur = user->likedpost->next;

    while (1)
    {
        if (cur == NULL)
        {
            free(prev);
            break;
        }
        del = prev;
        prev = prev->next;
        cur = cur->next;
        free(del);
    }
    return;
}

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
            break;
        }
        del = prev;
        prev = prev->next;
        cur = cur->next;
        free_post(del);
        free_likedpost(del);
        free(del->username);
        free(del->password);
    }
    return;
}

void leave(User *head, int *leave)
{
    free_user(head);
    *leave = 0;
}

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