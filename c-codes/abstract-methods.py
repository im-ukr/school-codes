import abc    #abstract class
class Shape(metaclass=abc.ABCMeta):
   @abc.abstractmethod     #abstract method
   def area(self):
      pass
class Rectangle(Shape):
   def __init__(self, x,y):
      self.l = x
      self.b=y
   def area(self):
      return self.l*self.b
r = Rectangle(10,20)
print ('area: ',r.area())