package Payload; 
public class ChangeUserInforRequest    { 
	 
	 
		private char name; 
	 
		private char username; 
	 
		private char email; 
	 
		private char address; 
	 
		private char mobileNo; 
	 
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
	 
		public final char getAddress() {
			return this.address;
		} 
		public final void setAddress(final char someAddress) {
			this.address = someAddress;
		} 
	 
		public final char getMobileNo() {
			return this.mobileNo;
		} 
		public final void setMobileNo(final char someMobileNo) {
			this.mobileNo = someMobileNo;
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