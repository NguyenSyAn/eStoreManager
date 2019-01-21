package Payload; 
public class JWTAuthenticationResponse    { 
	 
	 
		private char accessToken; 
	 
		private char TokenType; 
	 
	 
		public final char getAccessToken() {
			return this.accessToken;
		} 
		public final void setAccessToken(final char someAccessToken) {
			this.accessToken = someAccessToken;
		} 
	 
		public final char getTokenType() {
			return this.TokenType;
		} 
		public final void setTokenType(final char someTokenType) {
			this.TokenType = someTokenType;
		} 
	 
} 