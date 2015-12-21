__author__ = 'lizhifeng'

class IUser:
    def GetUser(self):
        pass
    def InsertUser(self):
        pass

class IDepartment:
    def GetDepartment(self):
        pass
    def  InsertDepartment(self):
        pass

class CAccessUser(IUser):
    def GetUser(self):
        print "Access GetUser"
    def InsertUser(self):
        print "Access InsertUser"

class CAccessDepartment(IDepartment):
    def  GetDepartment(self):
        print "accc GetDepartment"
    def InsertDepartment(self):
        print "access InsertDepartment"

class CSqlUser(IUser):
    def  GetUser(self):
        print "sql get user"
    def InsertUser(self):
        print "sql insert user"

class CSqlDepartment(IDepartment):
    def GetDepartment(self):
        print "sql get Departemnt"
    def InsertDepartment(self):
        print "sql insertdepartment"

class IFactory:
    def CreateUser(self):
        pass
    def CreateDepartment(self):
        pass

class AccessFactory(IFactory):
    def CreateUser(self):
        user = CAccessUser()
        return user
    def CreateDepartment(self):
        user  = CAccessDepartment()
        return user

class SqlFactory(IFactory):
    def CreateUser(self):
        user = CSqlUser()
        return user
    def CreateDepartment(self):
        user = CSqlDepartment()
        return user

if __name__ == "__main__":
