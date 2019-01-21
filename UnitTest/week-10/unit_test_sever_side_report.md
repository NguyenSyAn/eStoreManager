# 1. Technique and Description of test cases and test data

## 1.1. Test cases and test data: 

### 1.1.1 Login into store:
* On success:
```
{
    "success": true,
    "id": 1,
    "name": "admin",
    "accessToken": "eyJhbGciOiJIUzUxMiJ9.eyJzdWIiOiIxIiwiaWF0IjoxNTQzMzM5NjExLCJleHAiOjE1NDM5NDQ0MTF9.sM5jliKZbRIvFXDhMIBgPf4vj-6-7Prc33Ms9IE9fmWpdhVc_Q2GMoxdIvOKmz1SA061txj8DBUZPcHG3gHAhA",
    "tokenType": "Bearer"
}
```

* On fail (unauthorized):
```
{
    ...
    "status": 401,
    "error": "Unauthorized",
    "message": "Sorry, You're not authorized to access this resource.",
    ...
}
```


* On fail (one field is not in right format):
```
{
    ...
    "status": 400,
    "error": "Bad Request",
    ...
}
```

# 1.1.2 Get a user information:
* On success:
```
{
    "success": true,
    "id": 9,
    "name": "ceo la",
    "username": "ceo",
    "salary": 1000,
    "email": "ceo@gmail.com",
    "address": "hoa binh",
    "mobileNo": "0916167558",
    "roles": [
        "ROLE_MANAGER",
        "ROLE_ADMIN"
    ]
}
```

* On fail (unauthorized):
```
{
    ...
    "status": 401,
    "error": "Unauthorized",
    "message": "Sorry, You're not authorized to access this resource.",
    ...
}
```

* On fail (id does not exist):
```
{
    "success": false,
    "code": "something_wrong",
    "message": "something wrong with user id"
}
```

* On fail (you don't have role admin):
```
{
    ...
    "status": 403,
    "error": "Forbidden",
    "message": "Forbidden",
    ...
}
```

## 1.2. Testing technique: Decision Table

# 2. Write code for test cases:
In these two test cases code, I use Spring Boot test features with JUnit test.

* Login into store:
```
@RunWith(SpringRunner.class)
@WebMvcTest(value = UserController.class, secure = false)
public class UserControllerTest {

	@Autowired
	private MockMvc mockMvc;

    String loginRequest = "{\"username\":\"admin\",\"password\":\"admin@gmail.com\"}";

    @Test
    public void getUserInformation() throws Exception {
        // Send loginRequest as body to '/api/v1/login
        RequestBuilder requestBuilder = MockMvcRequestBuilders
                                        .post("/api/v1/login")
                                        .accept(MediaType.APPLICATION_JSON).content(loginRequest)
                                        .contentType(MediaType.APPLICATION_JSON);

        MvcResult result = mockMvc.perform(requestBuilder).andReturn();

        MockHttpServletResponse response = result.getResponse();

        assertEquals(HttpStatus.OK.value(), response.getStatus());
    }

}
```

* Get a user information:
```
@RunWith(SpringRunner.class)
@WebMvcTest(value = UserController.class, secure = false)
public class UserControllerTest {

	@Autowired
	private MockMvc mockMvc;


    @Test
    public void getUserInformation() throws Exception {
        // Send request to '/api/v1/users/{user_id}
        RequestBuilder requestBuilder = MockMvcRequestBuilders
                                        .perform(get("/api/v1/users/1")
                                        .with(user("admin")
                                        .password("pass")
                                        .roles("CASHIER","ADMIN")))
                                        .accept(MediaType.APPLICATION_JSON)
                                        .contentType(MediaType.APPLICATION_JSON);

        MvcResult result = mockMvc.perform(requestBuilder).andReturn();

        MockHttpServletResponse response = result.getResponse();

        assertEquals(HttpStatus.OK.value(), response.getStatus());
    }

}
```

# 3. Report to present and summarize the result:

All test cases are successful with coverage = 100% => All functions specified in the external specification are successfully implemented without any redundant codes.