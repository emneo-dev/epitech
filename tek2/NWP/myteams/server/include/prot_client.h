/*
** EPITECH PROJECT, 2021
** my_teams_rfc
** File description:
** prot_client
*/

#ifndef PROT_CLIENT_H_
    #define PROT_CLIENT_H_

    #include <uuid/uuid.h>

    #include "prot_pck.h"

    enum cli_pck_id {
        ID_LOGIN = 0,
        ID_DISCONNECT = 1,
        ID_USERS = 2,
        ID_USER = 3,
        ID_SEND = 4,
        ID_MESSAGES = 5,
        ID_SUB_TEAM = 6,
        ID_SUB_USR_TEAM = 7,
        ID_SUB_LIST_TEAMS = 8,
        ID_UNSUB_TEAM = 9,
        ID_CREATE_TEAM = 10,
        ID_CREATE_CHAN = 11,
        ID_CREATE_THREAD = 12,
        ID_CREATE_REPLY = 13,
        ID_LIST_TEAMS = 14,
        ID_LIST_CHANS = 15,
        ID_LIST_THREADS = 16,
        ID_LIST_REPLIES = 17,
        ID_INFO_USR = 18,
        ID_INFO_TEAM = 19,
        ID_INFO_CHAN = 20,
        ID_INFO_THREAD = 21,
        ID_SET_COMP = 22
    } __attribute__ ((__packed__));

    struct pck_login {
        struct pck pck;
        char username[32];
    } __attribute__ ((__packed__));

    struct pck_disconnect {
        struct pck pck;
    } __attribute__ ((__packed__));

    struct pck_users {
        struct pck pck;
    } __attribute__ ((__packed__));

    struct pck_user {
        struct pck pck;
        uuid_t user_uuid;
    } __attribute__ ((__packed__));

    struct pck_send {
        struct pck pck;
        uuid_t user_uuid;
        char msg[512];
    } __attribute__ ((__packed__));

    struct pck_messages {
        struct pck pck;
        uuid_t user_uuid;
    } __attribute__ ((__packed__));

    struct pck_sub_team {
        struct pck pck;
        uuid_t team_uuid;
    } __attribute__ ((__packed__));

    struct pck_sub_usr_team {
        struct pck pck;
        uuid_t team_uuid;
    } __attribute__ ((__packed__));

    struct pck_sub_list_teams {
        struct pck pck;
    } __attribute__ ((__packed__));

    struct pck_unsub_team {
        struct pck pck;
        uuid_t team_uuid;
    } __attribute__ ((__packed__));

    struct pck_create_team {
        struct pck pck;
        char team_name[32];
        char team_desc[255];
    } __attribute__ ((__packed__));

    struct pck_create_chan {
        struct pck pck;
        uuid_t team_uuid;
        char team_name[32];
        char team_description[255];
    } __attribute__ ((__packed__));

    struct pck_create_thread {
        struct pck pck;
        uuid_t team_uuid;
        uuid_t chan_uuid;
        char thread_title[32];
        char thread_message[512];
    } __attribute__ ((__packed__));

    struct pck_create_reply {
        struct pck pck;
        uuid_t team_uuid;
        uuid_t chan_uuid;
        uuid_t thread_uuid;
        char reply_msg[512];
    } __attribute__ ((__packed__));

    struct pck_list_teams {
        struct pck pck;
    } __attribute__ ((__packed__));

    struct pck_list_chans {
        struct pck pck;
        uuid_t team_uuid;
    } __attribute__ ((__packed__));

    struct pck_list_threads {
        struct pck pck;
        uuid_t team_uuid;
        uuid_t chan_uuid;
    } __attribute__ ((__packed__));

    struct pck_list_replies {
        struct pck pck;
        uuid_t team_uuid;
        uuid_t chan_uuid;
        uuid_t thread_uuid;
    } __attribute__ ((__packed__));

    struct pck_info_usr {
        struct pck pck;
    } __attribute__ ((__packed__));

    struct pck_info_team {
        struct pck pck;
        uuid_t team_uuid;
    } __attribute__ ((__packed__));

    struct pck_info_chan {
        struct pck pck;
        uuid_t team_uuid;
        uuid_t chan_uuid;
    } __attribute__ ((__packed__));

    struct pck_info_thread {
        struct pck pck;
        uuid_t team_uuid;
        uuid_t chan_uuid;
        uuid_t thread_uuid;
    } __attribute__ ((__packed__));

    enum compression_type {
        NO_COMP = 0
    } __attribute__ ((__packed__));

    struct pck_set_comp {
        struct pck pck;
        enum compression_type comp_type;
    } __attribute__ ((__packed__));

#endif /* !PROT_CLIENT_H_ */
