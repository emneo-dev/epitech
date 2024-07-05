/*
** EPITECH PROJECT, 2021
** my_teams
** File description:
** callbacks
*/

#ifndef CALLBACKS_H_
    #define CALLBACKS_H_

    #include "prot_client.h"

    #include "client.h"
    #include "error.h"

    error_t on_login_pck(const struct pck_login *pck, client_t *client);
    error_t on_disconnect_pck(const struct pck_disconnect *pck,
        client_t *client);
    error_t on_users_pck(const struct pck_users *pck, client_t *client);
    error_t on_user_pck(const struct pck_user *pck, client_t *client);
    error_t on_send_pck(const struct pck_send *pck, client_t *client);
    error_t on_messages_pck(const struct pck_messages *pck, client_t *client);
    error_t on_sub_team_pck(const struct pck_sub_team *pck, client_t *client);
    error_t on_sub_usr_team_pck(const struct pck_sub_usr_team *pck,
        client_t *client);
    error_t on_sub_list_teams_pck(const struct pck_sub_list_teams *pck,
        client_t *client);
    error_t on_unsub_team_pck(const struct pck_unsub_team *pck,
        client_t *client);
    error_t on_create_team_pck(const struct pck_create_team *pck,
        client_t *client);
    error_t on_create_chan_pck(const struct pck_create_chan *pck,
        client_t *client);
    error_t on_create_thread_pck(const struct pck_create_thread *pck,
        client_t *client);
    error_t on_create_reply_pck(const struct pck_create_reply *pck,
        client_t *client);
    error_t on_list_teams_pck(const struct pck_list_teams *pck,
        client_t *client);
    error_t on_list_chans_pck(const struct pck_list_chans *pck,
        client_t *client);
    error_t on_list_treads_pck(const struct pck_list_threads *pck,
        client_t *client);
    error_t on_list_replies_pck(const struct pck_list_replies *pck,
        client_t *client);
    error_t on_info_usr_pck(const struct pck_info_usr *pck, client_t *client);
    error_t on_info_team_pck(const struct pck_info_team *pck,
        client_t *client);
    error_t on_info_chan_pck(const struct pck_info_chan *pck, client_t *client);
    error_t on_info_thread_pck(const struct pck_info_thread *pck,
        client_t *client);
    error_t on_set_comp_pck(const struct pck_set_comp *pck, client_t *client);

#endif /* !CALLBACKS_H_ */
