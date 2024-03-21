DELIMITER $$
CREATE PROCEDURE addpetoteam(num char(20),tea char(5))
BEGIN

declare Pid int;
declare Wid int;
declare Tid int;
declare Cid int;

select Police_ID into cid from Police where Police_Num = num;
select Workobject_ID into Wid from Workobject where Workobject_Num = num;
select Team_ID into Tid from Team where Team_Num =tea;
select Case_ID into Cid from Case_ where Case_Num =tea;

if Pid < 0 or Pid <=> null then
    if Wid < 0 or Wid <=> null then
        select '此人不存在';
    else if Cid < 0 or Cid <=> null then
            select '此案件不存在';
         else
             insert into CaseList_Workobject(Case_Num,Workobject_Num) values (tea,num);

else if Tid < 0 or Tid <=> null then
        select '此团队不存在';
     else
        insert into TeamList_Member(Police_Num,Team_Num) values (num,tea);
end if;

END; $$