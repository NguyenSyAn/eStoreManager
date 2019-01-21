1. Database Manager System for project: MySql
2. Detail design for database:

* customer

+------------+--------------+------+-----+---------+----------------+
| Field      | Type         | Null | Key | Default | Extra          |
+------------+--------------+------+-----+---------+----------------+
| id         | bigint(20)   | NO   | PRI | NULL    | auto_increment |
| created_at | datetime     | NO   |     | NULL    |                |
| updated_at | datetime     | NO   |     | NULL    |                |
| address    | varchar(100) | YES  |     | NULL    |                |
| email      | varchar(40)  | YES  | UNI | NULL    |                |
| mobile_no  | varchar(255) | YES  |     | NULL    |                |
| name       | varchar(40)  | YES  |     | NULL    |                |
+------------+--------------+------+-----+---------+----------------+

Index: name

* import_bill_products

+----------------+------------+------+-----+---------+-------+
| Field          | Type       | Null | Key | Default | Extra |
+----------------+------------+------+-----+---------+-------+
| import_bill_id | bigint(20) | NO   | PRI | NULL    |       |
| product_id     | bigint(20) | NO   | PRI | NULL    |       |
+----------------+------------+------+-----+---------+-------+

Index: import_bill_id

* import_bills

+------------+------------+------+-----+---------+----------------+
| Field      | Type       | Null | Key | Default | Extra          |
+------------+------------+------+-----+---------+----------------+
| id         | bigint(20) | NO   | PRI | NULL    | auto_increment |
| created_at | datetime   | NO   |     | NULL    |                |
| updated_at | datetime   | NO   |     | NULL    |                |
| user       | tinyblob   | YES  |     | NULL    |                |
+------------+------------+------+-----+---------+----------------+

Index: id

* invoices

+-------------+--------------+------+-----+---------+----------------+
| Field       | Type         | Null | Key | Default | Extra          |
+-------------+--------------+------+-----+---------+----------------+
| id          | bigint(20)   | NO   | PRI | NULL    | auto_increment |
| created_at  | datetime     | NO   |     | NULL    |                |
| updated_at  | datetime     | NO   |     | NULL    |                |
| amount      | float        | YES  |     | NULL    |                |
| description | varchar(100) | YES  |     | NULL    |                |
| purpose     | varchar(100) | YES  |     | NULL    |                |
+-------------+--------------+------+-----+---------+----------------+

Index: id

* order_bill_products

+---------------+------------+------+-----+---------+-------+
| Field         | Type       | Null | Key | Default | Extra |
+---------------+------------+------+-----+---------+-------+
| order_bill_id | bigint(20) | NO   | PRI | NULL    |       |
| product_id    | bigint(20) | NO   | PRI | NULL    |       |
+---------------+------------+------+-----+---------+-------+

Index: order_bill_id

* order_bils

+------------+------------+------+-----+---------+----------------+
| Field      | Type       | Null | Key | Default | Extra          |
+------------+------------+------+-----+---------+----------------+
| id         | bigint(20) | NO   | PRI | NULL    | auto_increment |
| created_at | datetime   | NO   |     | NULL    |                |
| updated_at | datetime   | NO   |     | NULL    |                |
| customer   | tinyblob   | YES  |     | NULL    |                |
| user       | tinyblob   | YES  |     | NULL    |                |
+------------+------------+------+-----+---------+----------------+

Index: id

* product_types

+------------+-------------+------+-----+---------+----------------+
| Field      | Type        | Null | Key | Default | Extra          |
+------------+-------------+------+-----+---------+----------------+
| id         | bigint(20)  | NO   | PRI | NULL    | auto_increment |
| created_at | datetime    | NO   |     | NULL    |                |
| updated_at | datetime    | NO   |     | NULL    |                |
| barcode    | varchar(40) | YES  |     | NULL    |                |
| name       | varchar(40) | YES  |     | NULL    |                |
| price      | float       | NO   |     | NULL    |                |
| unit       | varchar(40) | YES  |     | NULL    |                |
+------------+-------------+------+-----+---------+----------------+

Index: barcode

* products

+--------------+------------+------+-----+---------+----------------+
| Field        | Type       | Null | Key | Default | Extra          |
+--------------+------------+------+-----+---------+----------------+
| id           | bigint(20) | NO   | PRI | NULL    | auto_increment |
| created_at   | datetime   | NO   |     | NULL    |                |
| updated_at   | datetime   | NO   |     | NULL    |                |
| product_type | tinyblob   | NO   |     | NULL    |                |
| quantities   | int(11)    | NO   |     | NULL    |                |
| supplier     | tinyblob   | NO   |     | NULL    |                |
+--------------+------------+------+-----+---------+----------------+

Index: id

* roles

+-------+-------------+------+-----+---------+----------------+
| Field | Type        | Null | Key | Default | Extra          |
+-------+-------------+------+-----+---------+----------------+
| id    | bigint(20)  | NO   | PRI | NULL    | auto_increment |
| name  | varchar(60) | YES  | UNI | NULL    |                |
+-------+-------------+------+-----+---------+----------------+

Index: name

* suppliers

+------------+--------------+------+-----+---------+----------------+
| Field      | Type         | Null | Key | Default | Extra          |
+------------+--------------+------+-----+---------+----------------+
| id         | bigint(20)   | NO   | PRI | NULL    | auto_increment |
| created_at | datetime     | NO   |     | NULL    |                |
| updated_at | datetime     | NO   |     | NULL    |                |
| address    | varchar(100) | YES  |     | NULL    |                |
| email      | varchar(40)  | YES  | UNI | NULL    |                |
| mobile_no  | varchar(255) | YES  |     | NULL    |                |
| name       | varchar(40)  | YES  |     | NULL    |                |
+------------+--------------+------+-----+---------+----------------+

Index: name

* user_roles

+---------+------------+------+-----+---------+-------+
| Field   | Type       | Null | Key | Default | Extra |
+---------+------------+------+-----+---------+-------+
| user_id | bigint(20) | NO   | PRI | NULL    |       |
| role_id | bigint(20) | NO   | PRI | NULL    |       |
+---------+------------+------+-----+---------+-------+

Index: user_id

* users

+------------+--------------+------+-----+---------+----------------+
| Field      | Type         | Null | Key | Default | Extra          |
+------------+--------------+------+-----+---------+----------------+
| id         | bigint(20)   | NO   | PRI | NULL    | auto_increment |
| created_at | datetime     | NO   |     | NULL    |                |
| updated_at | datetime     | NO   |     | NULL    |                |
| address    | varchar(100) | YES  |     | NULL    |                |
| email      | varchar(40)  | YES  | UNI | NULL    |                |
| mobile_no  | varchar(255) | YES  |     | NULL    |                |
| name       | varchar(40)  | YES  |     | NULL    |                |
| password   | varchar(100) | YES  |     | NULL    |                |
| salary     | bigint(20)   | YES  |     | NULL    |                |
| username   | varchar(15)  | YES  | UNI | NULL    |                |
+------------+--------------+------+-----+---------+----------------+

Index: username

3. Implement in index in my DBMS

Using notation in framework spring boot to create MySQL tables with indices, for example:

@Entity
@Indices({
    @Index(members={"lastName","firstName"})
    @Index(members={"firstName"}, unique="true")
}
public class EntityWithCompositeIndex {
    String firstName;
    String lastName;
}

For all the tables, we choose the field we use for searching mostly as indices