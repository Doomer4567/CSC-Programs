Create table tblUsers (
    Email varchar(320),
    FirstName varchar(25),
    LastName varchar(35),
    Password varchar(250),
    Primary Key (Email)
);


select Email, firstname FROM tblUsers;

insert INTO tblUsers Values('ejbyker42@tntech.edu','Ethan','Byker','TokyoGhoul!');
insert INTO tblUsers Values('bsimpson@springfieldelementry.edu','Bart','Simspson','Eatmyshorts');
insert INTO tblUsers Values('homerjsimpson@springfieldnuc.com','Homer','Simpson','Doh!');
insert into tblUsers values('homersimpson@springfieldnuc.com','Homer','Simpson','Doh!');


delete from tblUsers Where Email='homersimpson@speingfieldnuc.com';

update tblUSers set password='KeepYourFingerOfMyButterfinger' where Email = 'bsimpson@springfieldelementry.edu';

drop table tblCharacters;
Update tblCharacters Set ShowTitle = 'Archer' Where CharacterID = 'ABC124';
select FirstName,
    LastName
    from tblCharacters;

DROP table tblCharacters;

Describe tblCharacters;

create table tblCharacters (
    CharacterID varchar(50),
    FirstName varchar(25),
    LastName varchar(35),
    CharacterShow varchar(100),
    Primary Key (CharacterID)
);
insert into tblCHaracters (FirstName,LastName,ShowTitle,CharacterID) values('Bart', 'Simpson', 'TheSimpsons','ABC124');
insert into tblCharacters (FirstName,LastName,ShowTitle) values('384629', 'Sonic', 'The HedgeHog', 'Sonic Boom');

delete from tblCharacters Where CharacterID='ABC124';
