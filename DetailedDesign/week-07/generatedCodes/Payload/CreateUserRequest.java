package Payload; 
public class CreateUserRequest    { 
	 
	 
		private char name; 
	 
		private char username; 
	 
		private char email; 
	 
		private char password; 
	 
		private int salary; 
	 
		private char roles; 
	 
	 
		public final char getName() {
			return this.name;
		} 
		public final void setName(final char someName) {
			this.name = someName;
		} 
	 
		public final char getUsername() {
			return this.username;
		} 
		public final void setUsername(final char someUsername) {
			this.username = someUsername;
		} 
	 
		public final char getEmail() {
			return this.email;
		} 
		public final void setEmail(final char someEmail) {
			this.email = someEmail;
		} 
	 
		public final char getPassword() {
			return this.password;
		} 
		public final void setPassword(final char somePassword) {
			this.password = somePassword;
		} 
	 
		public final int getSalary() {
			return this.salary;
		} 
		public final void setSalary(final int someSalary) {
			this.salary = someSalary;
		} 
	 
		public final char getRoles() {
			return this.roles;
		} 
		public final void setRoles(final char someRoles) {
			this.roles = someRoles;
		} 
	 
} 