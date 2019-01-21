# 1-  Relationships between actors : generalization, association

### Generalization 

An actor become heir to another actor. 

An actor A is a generalization of an actor B if the actor A can be substituted by the actor B

### Association

The association is not a relationship between actors, it is the relationship between the actor and the use case which in the case of a diagram is represented by an arrow.


# 2- Relationships between use cases: include, extend, generalization 
      
### Extend 

It extends the base use case and adds more functionality to the system.

A use case A extends a use case B when the use case A can be called during the execution of the use case B. Extension is optional.

### Include 

A case A includes a case B if the behavior described by case A includes the behavior of case B.

Inclusions can also break down a complex case into simpler sub-cases
	
### Generalization 

The behavior of the ancestor is inherited by the descendant. This is used when there is common behavior between two use cases.

A case A is a generalization of a case B if B is a special case of A.


