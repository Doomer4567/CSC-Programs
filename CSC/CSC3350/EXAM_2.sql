
CREATE TABLE tblEvents (
	event_id INT AUTO_INCREMENT,
    event_name VARCHAR(100),
    event_date DATE,
    venue VARCHAR(100),
    ticket_price DECIMAL(6, 2),
    PRIMARY KEY (event_id)
);

CREATE TABLE tblCustomers (
	customer_id INT AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    email VARCHAR(100),
    membership_level VARCHAR(20),
    PRIMARY KEY (customer_id)
);

CREATE TABLE tblTickets (
	ticket_id INT AUTO_INCREMENT,
    customer_id INT,
    event_id INT,
    purchase_date DATE,
    quantity INT,
    total_amount DECIMAL(8,2),
    PRIMARY KEY (ticket_id),
    FOREIGN KEY (customer_id) REFERENCES tblCustomers(customer_id),
    FOREIGN KEY (event_id) REFERENCES tblEvents(event_id)
);

CREATE TABLE tblSeats (
	seat_id INT AUTO_INCREMENT,
    ticket_id INT,
    seat_number VARCHAR(5),
    section VARCHAR(10),
    PRIMARY KEY (seat_id),
    FOREIGN KEY (ticket_id) REFERENCES tblTickets(ticket_id)
);

#5
SELECT * FROM tblevents WHERE venue = 'Blue Note Club';

#6
SELECT concat(first_name," ",last_name) as "Customer Name", event_name as "Event Name",quantity as "Ticket Qty" FROM tbltickets lEFT JOIN tblevents on tblevents.event_id = tbltickets.event_id left join tblcustomers on tblcustomers.customer_id = tbltickets.customer_id;

#7
SELECT COUNT(DISTINCT customer_id) FROM tblTickets; 

#8
SELECT tbltickets.customer_id,sum(total_amount) AS Total FROM tbltickets INNER JOIN tblcustomers ON tblcustomers.customer_id = tbltickets.customer_id GROUP BY tbltickets.customer_id ORDER BY tbltickets.customer_id DESC;

#9
SELECT sum(total_amount) AS "Total Revenue" FROM tbltickets;

#10
SELECT first_name,sum(quantity) FROM tbltickets inner JOIN tblcustomers on tbltickets.customer_id = tblcustomers.customer_id group by first_name, last_name;

#11
SELECT event_name,sum(total_amount) FROM tbltickets INNER JOIN tblevents ON tblevents.event_id = tbltickets.event_id GROUP BY event_name;

#12
SELECT AVG(quantity) from tbltickets;

Delimiter $
Create Trigger trgApplyDiscount
Before INSERT On tblTickets
For Each Row
Begin
	Set New.total_amount = Old.total_amount*.8;
End$
Delimiter ;

insert into tblevents Values('1','Test','01-01-0001','TEST','01.01');

#Debugging scripts
select * from tblcustomers;
select * from tblevents;
select * from tbltickets;
select * from tblseats;

drop table tblseats;
drop table tbltickets;
drop table tblEvents;
drop table tblCustomers;
