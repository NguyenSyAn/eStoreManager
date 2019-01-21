# Scratch Design for client-server APIs

    *NOTE:* 
    - This document is written to design Restful API for client-server communication.
    - We used some advices from this link: [https://codeplanet.io/principles-good-restful-api-design/](https://codeplanet.io/principles-good-restful-api-design/)


## 1. Global Configurations:
    - Base of v1 APIs: /api/v1/
    - Always use HTTP 200 code to response client.

## 2. User - Employee Management APIs
    
### 2.1. LOGIN: Login into store

#### 2.1.1. REQUEST
- PATH: /api/v1/login
- METHOD: POST
- HEADER: 
    + Content-type: application/json
- BODY:
~~~json
    {
        username: '<username or email>',
        password: '<hashed_password>'
    }
~~~

#### 2.1.2. RESPONSE
##### ON SUCCESS:
~~~json
    {
        success: true,
        code: 0,
        token: '<client token>'
    }
~~~
##### ON WRONG USERNAME OR PASSWORD:
~~~json
    {
        success: false,
        code: 1,
        message: 'Wrong username or password'
    }
~~~

### 2.1. LOGIN: Login into store

#### 2.1.1. REQUEST
- PATH: /api/v1/login
- METHOD: POST
- HEADER: 
    + Content-type: application/json
- BODY:
~~~json
    {
        username: '<username or email>',
        password: '<password>'
    }
~~~

#### 2.1.2. RESPONSE
##### ON SUCCESS:
~~~json
    {
        success: true,
        code: 'login_success',
        token: '<client token>',
        roles: ['<roles>']
    }
~~~
- `<client token>`: STRING:  new generated access token for client app.
- `<roles>`: STRING ARRAY: list of roles of the user. Each role is: `admin`, `warehouse_manager`, `cashier` or `other`.
##### ON WRONG USERNAME OR PASSWORD:
~~~json
    {
        success: false,
        code: 'wrong_login_info',
        message: 'Wrong username or password'
    }
~~~

### 2.2. USERS INFO:  Get information of all user:

#### 2.2.1. REQUEST
- PATH: /api/v1/users
- METHOD: GET
- HEADER: 
    + Authorization: Bearer JWT
    + Token: <client token>
- BODY:

#### 2.2.2. RESPONSE
##### ON SUCCESS:
~~~json
    {
        success: true,
        data: [
            {
                user_id: <user_id>,
                username: '<username>',
                fullname: '<fullname>',
                email: '<email>',
                address: '<address>',
                salary: <salary>,
                phone: '<phone number>',
                roles: ['<role1>', '<role2>'...]
            },
            {
                user_id: <user_id>,
                username: '<username>',
                fullname: '<fullname>',
                email: '<email>',
                address: '<address>',
                salary: <salary>,
                phone: '<phone number>',
                roles: ['<role1>', '<role2>'...]
            },
            ...
        ]
    }
~~~
##### ON PERMISSION DENIED
~~~json
    {
        success: false,
        code: 'permission_denied',
        message: 'You dont have permission to access this area.'
    }
~~~
##### ON TOKEN INVALID
~~~json
    {
        success: false,
        code: 'invalid_token',
        message: 'Invalid token.'
    }
~~~

### 2.2. UPDATE USER INFO:  Update information of 1 user:

#### 2.2.1. REQUEST
- PATH: /api/v1/users/<user_id>
- METHOD: PUT
- PRE-AUTHORIZE: ROLE_ADMIN
- HEADER: 
    + Authorization: Bearer JWT
    + Token: <client token>
- BODY:
~~~json
 {
    username: '<username>',
    fullname: '<fullname>',
    email: '<email>',
    address: '<address>',
    salary: <salary>,
    phone: '<phone number>',
    roles: ['<role1>', '<role2>'...]
}
~~~
- `username`, `fullname`, `email`, `address`, `salary`, `phone`, `roles` are all optional.

#### 2.2.2. RESPONSE
##### ON SUCCESS:
~~~json
    {
        success: true
    }
~~~
##### ON PERMISSION DENIED
~~~json
    {
        success: false,
        code: 'permission_denied',
        message: 'You dont have permission to access this area.'
    }
~~~
##### ON TOKEN INVALID
~~~json
    {
        success: false,
        code: 'invalid_token',
        message: 'Invalid token.'
    }
~~~

### 2.3. CREATE USER:  Create 1 user

#### 2.3.1. REQUEST
- PATH: /api/v1/users
- METHOD: POST
- PRE-AUTHORIZE: ROLE_ADMIN
- HEADER: 
    + Authorization: Bearer JWT
    + Token: <client token>
- BODY:
~~~json
 {
    username: '<username>',
    password: '<hashed_password>'
    fullname: '<fullname>',
    email: '<email>',
    address: '<address>',
    salary: <salary>,
    phone: '<phone number>',
    roles: ['<role1>', '<role2>'...]
}
~~~
- `username`, `password` are required.
- `fullname`, `email`, `address`, `salary`, `phone`, `roles` are all optional.

#### 2.3.2. RESPONSE
##### ON SUCCESS:
~~~json
    {
        success: true,
        user_id: <user_id>
    }
~~~
##### ON PERMISSION DENIED
~~~json
    {
        success: false,
        code: 'permission_denied',
        message: 'You dont have permission to access this area.'
    }
~~~
##### ON TOKEN INVALID
~~~json
    {
        success: false,
        code: 'invalid_token',
        message: 'Invalid token.'
    }
~~~

### 2.4. MODIFY USER:  Modify user information. Used by Admin and user themself:

#### 2.4.1. REQUEST
- PATH: /api/v1/users/<user_id>
- METHOD: DELETE
- PRE-AUTHORIZE: ROLE_ADMIN, ROLE_MANAGER, ROLE_CASHIER
- HEADER: 
    + Authorization: Bearer JWT
    + Token: <client token>
- BODY:
~~~json
 {
    username: '<username>',
    fullname: '<fullname>',
    email: '<email>',
    address: '<address>',
    salary: <salary>,
    phone: '<phone number>',
    roles: ['<role1>', '<role2>'...]
}
~~~
- `username`, `fullname`, `email`, `address`, `salary`, `phone`, `roles` are all optional.
- Only `ROLE_ADMIN` can modify `salary` and `roles`.
- `ROLE_ADMIN` can modify information of any user. other Users only can modify their information (not information of someone else).

#### 2.4.2. RESPONSE
##### ON SUCCESS:
~~~json
    {
        success: true
    }
~~~
##### ON PERMISSION DENIED
~~~json
    {
        success: false,
        code: 'permission_denied',
        message: 'You dont have permission to access this area.'
    }
~~~
##### ON TOKEN INVALID
~~~json
    {
        success: false,
        code: 'invalid_token',
        message: 'Invalid token.'
    }
~~~

### 2.5. DELETE USER:  Delete 1 user from database:

#### 2.5.1. REQUEST
- PATH: /api/v1/users/<user_id>
- METHOD: DELETE
- PRE-AUTHORIZE: ROLE_ADMIN
- HEADER: 
    + Authorization: Bearer JWT
    + Token: <client token>
- BODY:
~~~json
 {
    username: '<username>',
    fullname: '<fullname>',
    email: '<email>',
    address: '<address>',
    salary: <salary>,
    phone: '<phone number>',
    roles: ['<role1>', '<role2>'...]
}
~~~
- `username`, `fullname`, `email`, `address`, `salary`, `phone`, `roles` are all optional.

#### 2.5.2. RESPONSE
##### ON SUCCESS:
~~~json
    {
        success: true
    }
~~~
##### ON PERMISSION DENIED
~~~json
    {
        success: false,
        code: 'permission_denied',
        message: 'You dont have permission to access this area.'
    }
~~~
##### ON TOKEN INVALID
~~~json
    {
        success: false,
        code: 'invalid_token',
        message: 'Invalid token.'
    }
~~~

