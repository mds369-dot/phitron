### **Database Design Strategies**
1. **Top-Down Design**:
   - Starts from high-level abstractions and refines them into specific tables and relationships.
   - Focus on creating an **Entity-Relationship Diagram (ERD)** first.
   
2. **Bottom-Up Design**:
   - Begins with detailed data and integrates it to form larger systems.
   - Focus on identifying attributes and their organization into tables.

3. **Inside-Out Design**:
   - Focuses on critical core tables/entities first and then builds relationships around them.

4. **Hybrid Design**:
   - Combines top-down and bottom-up strategies to balance abstraction and detail.

---

### **ERD Notations**
**Entity-Relationship Diagram (ERD)** notations are symbols used to represent entities, attributes, and relationships.

1. **Entity**:
   - **Rectangle**: Represents entities.
     - Example: `Students`.

2. **Attributes**:
   - **Oval**: Represents attributes.
     - Example: `Name`, `Age`.
   - **Key Attribute**: Represented by an oval with underlining.
     - Example: `StudentID`.

3. **Relationship**:
   - **Diamond**: Represents relationships between entities.
     - Example: `Enrollment`.

4. **Cardinality**:
   - **1:1**, **1:N**, or **M:N**: Specifies how many instances of an entity are related to others.

5. **Weak Entity**:
   - **Double Rectangle**: Represents an entity that depends on a strong entity.
     - Example: `Order Items` dependent on `Order`.

6. **Derived Attribute**:
   - **Dashed Oval**: Represents attributes that are calculated or derived.

---

### **ERD Primary Key and Relationships Between Tables**
1. **Primary Key**:
   - Unique identifier for an entity.
   - Represented as an **underlined attribute** in ERD.

2. **Relationships Between Tables**:
   - **1:1 Relationship**: One record in Table A corresponds to one record in Table B.
   - **1:N Relationship**: One record in Table A corresponds to multiple records in Table B.
   - **M:N Relationship**: Many records in Table A correspond to many records in Table B.

---

### **ERD Strong Entity and Weak Entity**
1. **Strong Entity**:
   - An independent entity that has a Primary Key.
   - Example: `Students` with a `StudentID` as the Primary Key.

2. **Weak Entity**:
   - Depends on a strong entity and does not have a sufficient Primary Key.
   - Identified by a **partial key** and a relationship with a strong entity.
   - Example:
     - Weak Entity: `OrderItem`
     - Strong Entity: `Order`

---

### **ERD Types of Attributes**
1. **Simple Attribute**:
   - Cannot be divided further.
   - Example: `Name`.

2. **Composite Attribute**:
   - Can be divided into sub-parts.
   - Example: `FullName` = `FirstName` + `LastName`.

3. **Derived Attribute**:
   - Can be calculated from other attributes.
   - Example: `Age` from `DateOfBirth`.

4. **Multivalued Attribute**:
   - Can have multiple values for a single entity.
   - Example: `PhoneNumbers`.

---

### **ERD Generalization and Specialization**
1. **Generalization**:
   - Process of abstracting common features from two or more entities into a higher-level entity.
   - **Example**: `Car` and `Truck` generalize to `Vehicle`.

2. **Specialization**:
   - Process of creating sub-entities from a higher-level entity based on specific attributes or roles.
   - **Example**: `Employee` specializes into `Manager` and `Technician`.

---

