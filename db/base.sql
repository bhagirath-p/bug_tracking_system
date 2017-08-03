show databases;
create database bug_tracking_system;
use bug_tracking_system;

#
#
#
create table user_info 
(
 user_id      varchar(5) primary key,
 user_name    varchar(20),
 password     varchar(20),
 account_type varchar(10),
 created      date
);

#
#
#
create table bug_info
(
 bug_id int(4) primary key NOT NULL AUTO_INCREMENT,
 bug_name        varchar(10),
 priority        varchar(10),
 project_name    varchar(10),
 bug_description varchar(30),
 comments        varchar(30),
 status          varchar(10),
 assigned_to     varchar(10)
);
