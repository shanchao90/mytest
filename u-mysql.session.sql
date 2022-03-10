create database polisecase;
use policecase;


select 1;

create table Rank_(
    Rank_Num INT unsigned,
    Rank_Name varchar(20) not null,
    Primary key (Rank_Num)
)Engine=innodb default charset=utf8;

insert into Rank_(Rank_Num,Rank_Name) 
values (1,'二级警员')
	  ,(2,'一级警员')
	  ,(3,'三级警司')
	  ,(4,'二级警司')
	  ,(5,'一级警司')
	  ,(6,'三级警督')
	  ,(7,'二级警督')
	  ,(8,'一级警督');

select * from Rank_;

create table Police(
    Police_ID INT unsigned auto_increment,
    Police_Name VARCHAR(20) not null,
	Person_Num CHAR(20) unique,
    Sex CHAR(2) check(Sex='男' or Sex='女'),
	Police_Num CHAR(20) unique,
    Rank_Num INT unsigned,
    Post VARCHAR(20) ,
    Primary key(Police_ID),
    constraint Police_Rank foreign key (Rank_Num) 
	references Rank_(Rank_Num)
)Engine=innodb default charset=utf8;





















