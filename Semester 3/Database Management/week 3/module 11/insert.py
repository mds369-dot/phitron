import mysql.connector

db_name = "python_test_db"

mydbconnection = mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="144950",
    database=db_name
)

mycursor = mydbconnection.cursor()

sqlquery = """
            INSERT INTO Student(Roll, Name)
            VALUES('101', 'Musa daNyal Shagor')
            """

mycursor.execute(sqlquery)
mydbconnection.commit()
print("Insert table successful")