class student:
	
	def __init__(self):
		self.age=None
		self.id = None
		self.marks = None
	
	def validate_age(self):
		if self.age>20:
			return True
		else:
			return False

	def validate_marks(self):
		if self.marks>0 and self.marks <100:
			return True
		else:
			return False 

	def check_qualification(self):
		if self.marks >65:
			return True
		else:
			return False

	def set_values(self,id1,a,m):
		self.id = id1
		self.age = a
		self.marks = m

	def get_values(self):
		print("ID ",self.id)
		print("Age ",self.age)
		print("Marks ",self.marks)


id1 = int(input("enter your id "))
age = int(input("enter your age "))
marks = int(input("enter your marks "))

stu = student()
stu.set_values(id1,age,marks)

if stu.validate_age():
	if stu.validate_marks():
		u = stu.check_qualification()
		if u:
			stu.get_values()
		else:
			print("Marks should be above 65")			
	else:
		print("Invalid marks")
else:
	print("Invalid age")


	

		
		
