1. Database Manager System for project: MySql
2. Detail design for database:

* users

| id | name | username | password | address | salary | email | mobileNo |
|---|---|---|---|---|---|---|---|
| 1 | Sy An | syan224 | 1324jkshdfob234f | 583 Vu Tong Phan | 2000 | syan224@gmail.com | 0917915518 |
| 2 | Viet Anh | vietanhdev | 12khfwe39nsdf3 | Bach Mai | 3000 | vietanhdev@gmail.com | 01693018197 |

* roles

| id | roleName |
| --- | --- |
| 1 | Admin |
| 2 | Manager |
| 3 | Cashier |

* user_roles

| user | role |
| --- | --- |
| 1 | 2 |
| 1 | 0 |
| 2 | 1 |
|2 | 0 |

* products

| id | name | price | quantities | unit | barcode |
|---|---|---|---|---|---|
| 1 | vina milk | 23000 | 100 | bottle | dfaj23e |
| 2 | shampoo | 50000 | 20 | bottle | 231jlsdf |

* suppliers

| id | name | email | mobileNo |
| --- | --- | --- | --- |
| 1 | vina | vina @gmail.com | 0983945382 | 

* supplier_products

| supplier | product |
| --- | --- |
| 1 | 1 |
| 1 | 3 |
| 2 | 4 |

* customers

| id | name | email | mobileNo |
| --- | --- | --- | --- |
| 0 | Theo | theo@gmail.com | 0342494343 |

* order_bills

| id | time |
| --- | --- |
| 1 | 1994-11-05T08:15:30-05:00 |
| 2 | 1995-11-05T08:20:30-05:00 |

* order_bill_users

| order_bill | user |
| --- | --- |
| 1 | 3 |
| 2 | 4 |

* order_bill_products

| order_bill | product |
| --- | --- |
| 1 | 12 |
| 1 | 13 |

* order_bill_customers

| order_bill | customer |
| --- | --- |
| 1 | 2 |
| 2 | 3 |

* import_bills

| id | time |
| --- | --- |
| 1 | 1994-11-05T08:15:30-05:00 |
| 2 | 1995-11-05T08:20:30-05:00 |

* import_bill_users

| import_bill | user |
| --- | --- |
| 1 | 3 |
| 2 | 4 |

* import_bill_products

| import_bill | products |
| --- | --- |
| 1 | 12 |
| 1 | 13 |

* import_bill_suppliers

| import_bill | supplier |
| --- | --- |
| 1 | 3 |
| 2 | 4 |

* invoice

| id | time | purpose | description | amount |
| --- | --- | --- | --- | --- |
| 1 | 1994-11-05T08:15:30-05:00 | pay salary | pay salary for employee | 2000 |
| 2 | 1994-11-05T08:15:30-05:00 | pay electric | pay electric bill to EVN | 300 |