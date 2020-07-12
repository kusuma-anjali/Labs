from tkinter import *

class movie(Frame):
	
	def __init__(self,master):
		Frame.__init__(self,master)
		self.grid()
		self.create_widgets()	
		

	def create_widgets(self):
	
		self.num = StringVar()			
		self.num.set("0")
		self.update_lang = StringVar()

		self.bumble = BooleanVar()
		self.harry = BooleanVar()
		self.sahoo = BooleanVar()

		self.res = Text(self,width = 40,height = 20 ,wrap =WORD)		
		self.res.grid(row = 8,column = 2,sticky=W)
		
		Label(self,text ="Select your language").grid(row=0,column=0,sticky=W)

		Radiobutton(self,text ="english",variable =self.update_lang , value = "english").grid(row = 1,column=0,sticky = W)
		Radiobutton(self,text ="Hindi",variable =self.update_lang , value = "hindi").grid(row = 1,column=1,sticky = W)
		Radiobutton(self,text ="Telugu",variable =self.update_lang , value = "telugu").grid(row = 1,column=2,sticky = W)

		Label(self,text ="Select your movie").grid(row=2,column=0,sticky=W)

		Checkbutton(self,text="Bumblebee",variable=self.bumble).grid(row=3,column=0,sticky=W)
		Checkbutton(self,text="harry potter",variable=self.harry).grid(row=3,column=1,sticky=W)
		Checkbutton(self,text="Sahoo",variable=self.sahoo).grid(row=3,column=2,sticky=W)
		
		Label(self,text ="Select no of seats").grid(row=4,column=0,sticky=W)		
		OptionMenu(self,self.num,"1","2","3").grid(row = 5,column = 0,sticky = W)		
		Button(self,text = "Book movie",command = self.submit).grid(row = 6,column = 1,sticky =W)
	
	
	def submit(self):
		lang = self.update_lang.get() 
		no = self.num.get()
		if lang =="":
			self.res.delete(0.0,END)
			self.res.insert(0.0,"Select a language")

		elif not self.bumble.get() and not self.harry.get() and not self.sahoo.get():
			self.res.delete(0.0,END)
			self.res.insert(0.0,"Select a movie")
		elif no=="0":
			self.res.delete(0.0,END)
			self.res.insert(0.0,"Select a seat")	
		else:
			self.res.delete(0.0,END)
			self.res.insert(0.0,"Booking success")		
		
		

root = Tk()
root.title("Movie Booking")
root.geometry("400x500")
app = movie(root)
root.mainloop()
