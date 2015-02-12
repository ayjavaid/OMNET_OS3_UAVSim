//
// Generated file, do not edit! Created by opp_msgc 4.4 from sim_std.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "sim_std_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}



class cObjectDescriptor : public cClassDescriptor
{
  public:
    cObjectDescriptor();
    virtual ~cObjectDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cObjectDescriptor);

cObjectDescriptor::cObjectDescriptor() : cClassDescriptor("cObject", "")
{
}

cObjectDescriptor::~cObjectDescriptor()
{
}

bool cObjectDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cObject *>(obj)!=NULL;
}

const char *cObjectDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "cogwheel";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cObjectDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int cObjectDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *cObjectDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "className",
        "fullName",
        "fullPath",
        "info",
        "detailedInfo",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int cObjectDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "className")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fullName")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fullPath")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "info")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "detailedInfo")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cObjectDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "string",
        "string",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *cObjectDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"hint")) return "C++ class name";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "If object is part of a module/gate vector: name with index";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"hint")) return "Hierarchical name, composed of full names of this object and its owners/parents";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"getter")) return "info";
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"hint")) return "Text provided by the object's \"info\" method";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"getter")) return "detailedInfo";
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"hint")) return "Text provided by the object's \"detailedInfo\" method";
            return NULL;
        default: return NULL;
    }
}

int cObjectDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cObject *pp = (cObject *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cObjectDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cObject *pp = (cObject *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getClassName());
        case 1: return oppstring2string(pp->getFullName());
        case 2: return oppstring2string(pp->getFullPath());
        case 3: return oppstring2string(pp->info());
        case 4: return oppstring2string(pp->detailedInfo());
        default: return "";
    }
}

bool cObjectDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cObject *pp = (cObject *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cObjectDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *cObjectDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cObject *pp = (cObject *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cNamedObjectDescriptor : public cClassDescriptor
{
  public:
    cNamedObjectDescriptor();
    virtual ~cNamedObjectDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cNamedObjectDescriptor);

cNamedObjectDescriptor::cNamedObjectDescriptor() : cClassDescriptor("cNamedObject", "cObject")
{
}

cNamedObjectDescriptor::~cNamedObjectDescriptor()
{
}

bool cNamedObjectDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cNamedObject *>(obj)!=NULL;
}

const char *cNamedObjectDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cNamedObjectDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cNamedObjectDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cNamedObjectDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "name",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cNamedObjectDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "name")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cNamedObjectDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cNamedObjectDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "An editable string attribute of the object, also used for fullName and fullPath";
            if (!strcmp(propertyname,"editable")) return "";
            return NULL;
        default: return NULL;
    }
}

int cNamedObjectDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cNamedObject *pp = (cNamedObject *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cNamedObjectDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cNamedObject *pp = (cNamedObject *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getName());
        default: return "";
    }
}

bool cNamedObjectDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cNamedObject *pp = (cNamedObject *)object; (void)pp;
    switch (field) {
        case 0: pp->setName((value)); return true;
        default: return false;
    }
}

const char *cNamedObjectDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cNamedObjectDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cNamedObject *pp = (cNamedObject *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cOwnedObjectDescriptor : public cClassDescriptor
{
  public:
    cOwnedObjectDescriptor();
    virtual ~cOwnedObjectDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cOwnedObjectDescriptor);

cOwnedObjectDescriptor::cOwnedObjectDescriptor() : cClassDescriptor("cOwnedObject", "cNamedObject")
{
}

cOwnedObjectDescriptor::~cOwnedObjectDescriptor()
{
}

bool cOwnedObjectDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cOwnedObject *>(obj)!=NULL;
}

const char *cOwnedObjectDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cOwnedObjectDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cOwnedObjectDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cOwnedObjectDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "owner",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cOwnedObjectDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "owner")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cOwnedObjectDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "cObject",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cOwnedObjectDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"hint")) return "Module or container this object belongs to";
            return NULL;
        default: return NULL;
    }
}

int cOwnedObjectDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cOwnedObject *pp = (cOwnedObject *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cOwnedObjectDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cOwnedObject *pp = (cOwnedObject *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOwner(); return out.str();}
        default: return "";
    }
}

bool cOwnedObjectDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cOwnedObject *pp = (cOwnedObject *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cOwnedObjectDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "cObject",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cOwnedObjectDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cOwnedObject *pp = (cOwnedObject *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(pp->getOwner()); break;
        default: return NULL;
    }
}

class cNoncopyableOwnedObjectDescriptor : public cClassDescriptor
{
  public:
    cNoncopyableOwnedObjectDescriptor();
    virtual ~cNoncopyableOwnedObjectDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cNoncopyableOwnedObjectDescriptor);

cNoncopyableOwnedObjectDescriptor::cNoncopyableOwnedObjectDescriptor() : cClassDescriptor("cNoncopyableOwnedObject", "cOwnedObject")
{
}

cNoncopyableOwnedObjectDescriptor::~cNoncopyableOwnedObjectDescriptor()
{
}

bool cNoncopyableOwnedObjectDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cNoncopyableOwnedObject *>(obj)!=NULL;
}

const char *cNoncopyableOwnedObjectDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cNoncopyableOwnedObjectDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cNoncopyableOwnedObjectDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cNoncopyableOwnedObjectDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cNoncopyableOwnedObjectDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cNoncopyableOwnedObjectDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cNoncopyableOwnedObjectDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cNoncopyableOwnedObjectDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cNoncopyableOwnedObject *pp = (cNoncopyableOwnedObject *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cNoncopyableOwnedObjectDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cNoncopyableOwnedObject *pp = (cNoncopyableOwnedObject *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cNoncopyableOwnedObjectDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cNoncopyableOwnedObject *pp = (cNoncopyableOwnedObject *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cNoncopyableOwnedObjectDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cNoncopyableOwnedObjectDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cNoncopyableOwnedObject *pp = (cNoncopyableOwnedObject *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cDefaultListDescriptor : public cClassDescriptor
{
  public:
    cDefaultListDescriptor();
    virtual ~cDefaultListDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cDefaultListDescriptor);

cDefaultListDescriptor::cDefaultListDescriptor() : cClassDescriptor("cDefaultList", "cNoncopyableOwnedObject")
{
}

cDefaultListDescriptor::~cDefaultListDescriptor()
{
}

bool cDefaultListDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cDefaultList *>(obj)!=NULL;
}

const char *cDefaultListDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cDefaultListDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cDefaultListDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cDefaultListDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "defaultList",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cDefaultListDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "defaultList")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cDefaultListDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "cOwnedObject",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cDefaultListDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "defaultListGet";
            if (!strcmp(propertyname,"group")) return "owned objects";
            if (!strcmp(propertyname,"hint")) return "List of objects directly held by this component";
            if (!strcmp(propertyname,"sizeGetter")) return "defaultListSize";
            return NULL;
        default: return NULL;
    }
}

int cDefaultListDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cDefaultList *pp = (cDefaultList *)object; (void)pp;
    switch (field) {
        case 0: return pp->defaultListSize();
        default: return 0;
    }
}

std::string cDefaultListDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cDefaultList *pp = (cDefaultList *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->defaultListGet(i); return out.str();}
        default: return "";
    }
}

bool cDefaultListDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cDefaultList *pp = (cDefaultList *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDefaultListDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "cOwnedObject",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cDefaultListDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cDefaultList *pp = (cDefaultList *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(pp->defaultListGet(i)); break;
        default: return NULL;
    }
}

class cDisplayStringDescriptor : public cClassDescriptor
{
  public:
    cDisplayStringDescriptor();
    virtual ~cDisplayStringDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cDisplayStringDescriptor);

cDisplayStringDescriptor::cDisplayStringDescriptor() : cClassDescriptor("cDisplayString", "")
{
}

cDisplayStringDescriptor::~cDisplayStringDescriptor()
{
}

bool cDisplayStringDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cDisplayString *>(obj)!=NULL;
}

const char *cDisplayStringDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cDisplayStringDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cDisplayStringDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cDisplayStringDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cDisplayStringDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cDisplayStringDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cDisplayStringDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "str";
            if (!strcmp(propertyname,"hint")) return "The editable display string itself";
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"setter")) return "parse";
            return NULL;
        default: return NULL;
    }
}

int cDisplayStringDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cDisplayString *pp = (cDisplayString *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cDisplayStringDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cDisplayString *pp = (cDisplayString *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        default: return "";
    }
}

bool cDisplayStringDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cDisplayString *pp = (cDisplayString *)object; (void)pp;
    switch (field) {
        case 0: pp->parse((value)); return true;
        default: return false;
    }
}

const char *cDisplayStringDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cDisplayStringDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cDisplayString *pp = (cDisplayString *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cPropertyDescriptor : public cClassDescriptor
{
  public:
    cPropertyDescriptor();
    virtual ~cPropertyDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cPropertyDescriptor);

cPropertyDescriptor::cPropertyDescriptor() : cClassDescriptor("cProperty", "cObject")
{
}

cPropertyDescriptor::~cPropertyDescriptor()
{
}

bool cPropertyDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cProperty *>(obj)!=NULL;
}

const char *cPropertyDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cPropertyDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int cPropertyDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cPropertyDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "isImplicit",
        "index",
        "value",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int cPropertyDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isImplicit")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cPropertyDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "string",
        "string",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *cPropertyDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isImplicit";
            if (!strcmp(propertyname,"group")) return "fields";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"group")) return "fields";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"getter")) return "info";
            if (!strcmp(propertyname,"hint")) return "Name and value";
            return NULL;
        default: return NULL;
    }
}

int cPropertyDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cProperty *pp = (cProperty *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPropertyDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cProperty *pp = (cProperty *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isImplicit());
        case 1: return oppstring2string(pp->getIndex());
        case 2: return oppstring2string(pp->info());
        default: return "";
    }
}

bool cPropertyDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cProperty *pp = (cProperty *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPropertyDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *cPropertyDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cProperty *pp = (cProperty *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cPropertiesDescriptor : public cClassDescriptor
{
  public:
    cPropertiesDescriptor();
    virtual ~cPropertiesDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cPropertiesDescriptor);

cPropertiesDescriptor::cPropertiesDescriptor() : cClassDescriptor("cProperties", "cObject")
{
}

cPropertiesDescriptor::~cPropertiesDescriptor()
{
}

bool cPropertiesDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cProperties *>(obj)!=NULL;
}

const char *cPropertiesDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cPropertiesDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cPropertiesDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cPropertiesDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "contents",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cPropertiesDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cPropertiesDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "cProperty",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cPropertiesDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "The property list";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumProperties";
            return NULL;
        default: return NULL;
    }
}

int cPropertiesDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cProperties *pp = (cProperties *)object; (void)pp;
    switch (field) {
        case 0: return pp->getNumProperties();
        default: return 0;
    }
}

std::string cPropertiesDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cProperties *pp = (cProperties *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cPropertiesDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cProperties *pp = (cProperties *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPropertiesDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "cProperty",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cPropertiesDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cProperties *pp = (cProperties *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(pp->get(i)); break;
        default: return NULL;
    }
}

class cComponentDescriptor : public cClassDescriptor
{
  public:
    cComponentDescriptor();
    virtual ~cComponentDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cComponentDescriptor);

cComponentDescriptor::cComponentDescriptor() : cClassDescriptor("cComponent", "cDefaultList")
{
}

cComponentDescriptor::~cComponentDescriptor()
{
}

bool cComponentDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cComponent *>(obj)!=NULL;
}

const char *cComponentDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cComponentDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int cComponentDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *cComponentDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "isModule",
        "componentType",
        "par",
        "props",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int cComponentDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isModule")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "componentType")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "par")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "props")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cComponentDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "cComponentType",
        "cPar",
        "cProperties",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *cComponentDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isModule";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this component is a module or a channel";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "The object that represents the type declaration for this component";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"getter")) return "par";
            if (!strcmp(propertyname,"group")) return "parameters, gates";
            if (!strcmp(propertyname,"hint")) return "Parameters";
            if (!strcmp(propertyname,"label")) return "parameters";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumParams";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"getter")) return "getProperties";
            if (!strcmp(propertyname,"group")) return "parameters, gates";
            if (!strcmp(propertyname,"hint")) return "Properties";
            if (!strcmp(propertyname,"label")) return "properties";
            return NULL;
        default: return NULL;
    }
}

int cComponentDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cComponent *pp = (cComponent *)object; (void)pp;
    switch (field) {
        case 2: return pp->getNumParams();
        default: return 0;
    }
}

std::string cComponentDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cComponent *pp = (cComponent *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isModule());
        case 1: {std::stringstream out; out << pp->getComponentType(); return out.str();}
        case 2: {std::stringstream out; out << pp->par(i); return out.str();}
        case 3: {std::stringstream out; out << pp->getProperties(); return out.str();}
        default: return "";
    }
}

bool cComponentDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cComponent *pp = (cComponent *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cComponentDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "cComponentType",
        "cPar",
        "cProperties",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *cComponentDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cComponent *pp = (cComponent *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<cObject *>(pp->getComponentType()); break;
        case 2: return (void *)static_cast<cObject *>(&pp->par(i)); break;
        case 3: return (void *)static_cast<cObject *>(pp->getProperties()); break;
        default: return NULL;
    }
}

class cChannelDescriptor : public cClassDescriptor
{
  public:
    cChannelDescriptor();
    virtual ~cChannelDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cChannelDescriptor);

cChannelDescriptor::cChannelDescriptor() : cClassDescriptor("cChannel", "cComponent")
{
}

cChannelDescriptor::~cChannelDescriptor()
{
}

bool cChannelDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cChannel *>(obj)!=NULL;
}

const char *cChannelDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "channel";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cChannelDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cChannelDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cChannelDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "displayString",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cChannelDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cChannelDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "cDisplayString",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cChannelDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Controls appearance of this channel in the GUI";
            return NULL;
        default: return NULL;
    }
}

int cChannelDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cChannel *pp = (cChannel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cChannelDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cChannel *pp = (cChannel *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDisplayString(); return out.str();}
        default: return "";
    }
}

bool cChannelDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cChannel *pp = (cChannel *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cChannelDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "cDisplayString",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cChannelDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cChannel *pp = (cChannel *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDisplayString()); break;
        default: return NULL;
    }
}

class cIdealChannelDescriptor : public cClassDescriptor
{
  public:
    cIdealChannelDescriptor();
    virtual ~cIdealChannelDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cIdealChannelDescriptor);

cIdealChannelDescriptor::cIdealChannelDescriptor() : cClassDescriptor("cIdealChannel", "cChannel")
{
}

cIdealChannelDescriptor::~cIdealChannelDescriptor()
{
}

bool cIdealChannelDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cIdealChannel *>(obj)!=NULL;
}

const char *cIdealChannelDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cIdealChannelDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cIdealChannelDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cIdealChannelDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cIdealChannelDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cIdealChannelDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cIdealChannelDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cIdealChannelDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cIdealChannel *pp = (cIdealChannel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cIdealChannelDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cIdealChannel *pp = (cIdealChannel *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cIdealChannelDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cIdealChannel *pp = (cIdealChannel *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cIdealChannelDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cIdealChannelDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cIdealChannel *pp = (cIdealChannel *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cDelayChannelDescriptor : public cClassDescriptor
{
  public:
    cDelayChannelDescriptor();
    virtual ~cDelayChannelDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cDelayChannelDescriptor);

cDelayChannelDescriptor::cDelayChannelDescriptor() : cClassDescriptor("cDelayChannel", "cChannel")
{
}

cDelayChannelDescriptor::~cDelayChannelDescriptor()
{
}

bool cDelayChannelDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cDelayChannel *>(obj)!=NULL;
}

const char *cDelayChannelDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cDelayChannelDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cDelayChannelDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cDelayChannelDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cDelayChannelDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cDelayChannelDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cDelayChannelDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cDelayChannelDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cDelayChannel *pp = (cDelayChannel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cDelayChannelDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cDelayChannel *pp = (cDelayChannel *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cDelayChannelDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cDelayChannel *pp = (cDelayChannel *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDelayChannelDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cDelayChannelDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cDelayChannel *pp = (cDelayChannel *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cDatarateChannelDescriptor : public cClassDescriptor
{
  public:
    cDatarateChannelDescriptor();
    virtual ~cDatarateChannelDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cDatarateChannelDescriptor);

cDatarateChannelDescriptor::cDatarateChannelDescriptor() : cClassDescriptor("cDatarateChannel", "cChannel")
{
}

cDatarateChannelDescriptor::~cDatarateChannelDescriptor()
{
}

bool cDatarateChannelDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cDatarateChannel *>(obj)!=NULL;
}

const char *cDatarateChannelDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cDatarateChannelDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int cDatarateChannelDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cDatarateChannelDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "isBusy",
        "transmissionFinishTime",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int cDatarateChannelDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isBusy")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transmissionFinishTime")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cDatarateChannelDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "simtime_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *cDatarateChannelDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isBusy";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If channel is currently transmitting";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If busy: when currently active transmissions will finish";
            return NULL;
        default: return NULL;
    }
}

int cDatarateChannelDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cDatarateChannel *pp = (cDatarateChannel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cDatarateChannelDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cDatarateChannel *pp = (cDatarateChannel *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isBusy());
        case 1: return double2string(pp->getTransmissionFinishTime());
        default: return "";
    }
}

bool cDatarateChannelDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cDatarateChannel *pp = (cDatarateChannel *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDatarateChannelDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *cDatarateChannelDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cDatarateChannel *pp = (cDatarateChannel *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cModuleDescriptor : public cClassDescriptor
{
  public:
    cModuleDescriptor();
    virtual ~cModuleDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cModuleDescriptor);

cModuleDescriptor::cModuleDescriptor() : cClassDescriptor("cModule", "cComponent")
{
}

cModuleDescriptor::~cModuleDescriptor()
{
}

bool cModuleDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cModule *>(obj)!=NULL;
}

const char *cModuleDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cModuleDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int cModuleDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *cModuleDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "id",
        "isSimple",
        "isVector",
        "index",
        "size",
        "displayString",
        "gate",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int cModuleDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isSimple")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isVector")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "size")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+5;
    if (fieldName[0]=='g' && strcmp(fieldName, "gate")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cModuleDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "bool",
        "int",
        "int",
        "cDisplayString",
        "cGate",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *cModuleDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Unique module ID -- IDs of deleted modules are not issued again";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"getter")) return "isSimple";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this is a simple module";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"getter")) return "isVector";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this module is part of a module vector";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If vector: index of this module in its module vector";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"getter")) return "size";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If vector: size of module vector this module belongs to";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Controls appearance of this module in the GUI";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"getter")) return "gateByOrdinal";
            if (!strcmp(propertyname,"group")) return "parameters, gates";
            if (!strcmp(propertyname,"hint")) return "Module gates";
            if (!strcmp(propertyname,"label")) return "gates";
            if (!strcmp(propertyname,"sizeGetter")) return "gateCount";
            return NULL;
        default: return NULL;
    }
}

int cModuleDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cModule *pp = (cModule *)object; (void)pp;
    switch (field) {
        case 6: return pp->gateCount();
        default: return 0;
    }
}

std::string cModuleDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cModule *pp = (cModule *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getId());
        case 1: return bool2string(pp->isSimple());
        case 2: return bool2string(pp->isVector());
        case 3: return long2string(pp->getIndex());
        case 4: return long2string(pp->size());
        case 5: {std::stringstream out; out << pp->getDisplayString(); return out.str();}
        case 6: {std::stringstream out; out << pp->gateByOrdinal(i); return out.str();}
        default: return "";
    }
}

bool cModuleDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cModule *pp = (cModule *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cModuleDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        "cDisplayString",
        "cGate",
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *cModuleDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cModule *pp = (cModule *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getDisplayString()); break;
        case 6: return (void *)static_cast<cObject *>(pp->gateByOrdinal(i)); break;
        default: return NULL;
    }
}

class cSimpleModuleDescriptor : public cClassDescriptor
{
  public:
    cSimpleModuleDescriptor();
    virtual ~cSimpleModuleDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cSimpleModuleDescriptor);

cSimpleModuleDescriptor::cSimpleModuleDescriptor() : cClassDescriptor("cSimpleModule", "cModule")
{
}

cSimpleModuleDescriptor::~cSimpleModuleDescriptor()
{
}

bool cSimpleModuleDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cSimpleModule *>(obj)!=NULL;
}

const char *cSimpleModuleDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "simple";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cSimpleModuleDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int cSimpleModuleDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *cSimpleModuleDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "isTerminated",
        "usesActivity",
        "stackSize",
        "stackUsage",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int cSimpleModuleDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isTerminated")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "usesActivity")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "stackSize")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "stackUsage")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cSimpleModuleDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *cSimpleModuleDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isTerminated";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this module has terminated";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"getter")) return "usesActivity";
            if (!strcmp(propertyname,"group")) return "activity";
            if (!strcmp(propertyname,"hint")) return "Whether this simple module was programmed using the \"activity\" or the \"handleMessage\" C++ method";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"group")) return "activity";
            if (!strcmp(propertyname,"hint")) return "If module uses \"activity\": stack size allocated for this module -- zero means info not available";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"group")) return "activity";
            if (!strcmp(propertyname,"hint")) return "If module uses \"activity\": stack actually used by this module -- zero means info not available";
            return NULL;
        default: return NULL;
    }
}

int cSimpleModuleDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cSimpleModule *pp = (cSimpleModule *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cSimpleModuleDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cSimpleModule *pp = (cSimpleModule *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isTerminated());
        case 1: return bool2string(pp->usesActivity());
        case 2: return ulong2string(pp->getStackSize());
        case 3: return ulong2string(pp->getStackUsage());
        default: return "";
    }
}

bool cSimpleModuleDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cSimpleModule *pp = (cSimpleModule *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cSimpleModuleDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *cSimpleModuleDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cSimpleModule *pp = (cSimpleModule *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cCompoundModuleDescriptor : public cClassDescriptor
{
  public:
    cCompoundModuleDescriptor();
    virtual ~cCompoundModuleDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cCompoundModuleDescriptor);

cCompoundModuleDescriptor::cCompoundModuleDescriptor() : cClassDescriptor("cCompoundModule", "cModule")
{
}

cCompoundModuleDescriptor::~cCompoundModuleDescriptor()
{
}

bool cCompoundModuleDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cCompoundModule *>(obj)!=NULL;
}

const char *cCompoundModuleDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "compound";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cCompoundModuleDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cCompoundModuleDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cCompoundModuleDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cCompoundModuleDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cCompoundModuleDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cCompoundModuleDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cCompoundModuleDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cCompoundModule *pp = (cCompoundModule *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cCompoundModuleDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cCompoundModule *pp = (cCompoundModule *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cCompoundModuleDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cCompoundModule *pp = (cCompoundModule *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cCompoundModuleDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cCompoundModuleDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cCompoundModule *pp = (cCompoundModule *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cComponentTypeDescriptor : public cClassDescriptor
{
  public:
    cComponentTypeDescriptor();
    virtual ~cComponentTypeDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cComponentTypeDescriptor);

cComponentTypeDescriptor::cComponentTypeDescriptor() : cClassDescriptor("cComponentType", "cNoncopyableOwnedObject")
{
}

cComponentTypeDescriptor::~cComponentTypeDescriptor()
{
}

bool cComponentTypeDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cComponentType *>(obj)!=NULL;
}

const char *cComponentTypeDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cComponentTypeDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cComponentTypeDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cComponentTypeDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cComponentTypeDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cComponentTypeDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cComponentTypeDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cComponentTypeDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cComponentType *pp = (cComponentType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cComponentTypeDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cComponentType *pp = (cComponentType *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cComponentTypeDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cComponentType *pp = (cComponentType *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cComponentTypeDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cComponentTypeDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cComponentType *pp = (cComponentType *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cModuleTypeDescriptor : public cClassDescriptor
{
  public:
    cModuleTypeDescriptor();
    virtual ~cModuleTypeDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cModuleTypeDescriptor);

cModuleTypeDescriptor::cModuleTypeDescriptor() : cClassDescriptor("cModuleType", "cComponentType")
{
}

cModuleTypeDescriptor::~cModuleTypeDescriptor()
{
}

bool cModuleTypeDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cModuleType *>(obj)!=NULL;
}

const char *cModuleTypeDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cModuleTypeDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cModuleTypeDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cModuleTypeDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "isNetwork",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cModuleTypeDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isNetwork")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cModuleTypeDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cModuleTypeDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isNetwork";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this module type can be used as toplevel module";
            return NULL;
        default: return NULL;
    }
}

int cModuleTypeDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cModuleType *pp = (cModuleType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cModuleTypeDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cModuleType *pp = (cModuleType *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isNetwork());
        default: return "";
    }
}

bool cModuleTypeDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cModuleType *pp = (cModuleType *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cModuleTypeDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cModuleTypeDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cModuleType *pp = (cModuleType *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cChannelTypeDescriptor : public cClassDescriptor
{
  public:
    cChannelTypeDescriptor();
    virtual ~cChannelTypeDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cChannelTypeDescriptor);

cChannelTypeDescriptor::cChannelTypeDescriptor() : cClassDescriptor("cChannelType", "cComponentType")
{
}

cChannelTypeDescriptor::~cChannelTypeDescriptor()
{
}

bool cChannelTypeDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cChannelType *>(obj)!=NULL;
}

const char *cChannelTypeDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cChannelTypeDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cChannelTypeDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cChannelTypeDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cChannelTypeDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cChannelTypeDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cChannelTypeDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cChannelTypeDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cChannelType *pp = (cChannelType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cChannelTypeDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cChannelType *pp = (cChannelType *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cChannelTypeDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cChannelType *pp = (cChannelType *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cChannelTypeDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cChannelTypeDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cChannelType *pp = (cChannelType *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cRegistrationListDescriptor : public cClassDescriptor
{
  public:
    cRegistrationListDescriptor();
    virtual ~cRegistrationListDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cRegistrationListDescriptor);

cRegistrationListDescriptor::cRegistrationListDescriptor() : cClassDescriptor("cRegistrationList", "cNamedObject")
{
}

cRegistrationListDescriptor::~cRegistrationListDescriptor()
{
}

bool cRegistrationListDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cRegistrationList *>(obj)!=NULL;
}

const char *cRegistrationListDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cRegistrationListDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cRegistrationListDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cRegistrationListDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "contents",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cRegistrationListDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cRegistrationListDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "cObject",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cRegistrationListDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "Contained objects";
            if (!strcmp(propertyname,"sizeGetter")) return "size";
            return NULL;
        default: return NULL;
    }
}

int cRegistrationListDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cRegistrationList *pp = (cRegistrationList *)object; (void)pp;
    switch (field) {
        case 0: return pp->size();
        default: return 0;
    }
}

std::string cRegistrationListDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cRegistrationList *pp = (cRegistrationList *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cRegistrationListDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cRegistrationList *pp = (cRegistrationList *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cRegistrationListDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "cObject",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cRegistrationListDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cRegistrationList *pp = (cRegistrationList *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(pp->get(i)); break;
        default: return NULL;
    }
}

class cGateDescriptor : public cClassDescriptor
{
  public:
    cGateDescriptor();
    virtual ~cGateDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cGateDescriptor);

cGateDescriptor::cGateDescriptor() : cClassDescriptor("cGate", "cObject")
{
}

cGateDescriptor::~cGateDescriptor()
{
}

bool cGateDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cGate *>(obj)!=NULL;
}

const char *cGateDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "gate";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cGateDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount(object) : 14;
}

unsigned int cGateDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<14) ? fieldTypeFlags[field] : 0;
}

const char *cGateDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "id",
        "isVector",
        "index",
        "deliverOnReceptionStart",
        "channel",
        "previousGate",
        "nextGate",
        "pathStartGate",
        "pathEndGate",
        "isConnectedOutside",
        "isConnectedInside",
        "isConnected",
        "isPathOK",
    };
    return (field>=0 && field<14) ? fieldNames[field] : NULL;
}

int cGateDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isVector")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "deliverOnReceptionStart")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "previousGate")==0) return base+6;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextGate")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathStartGate")==0) return base+8;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathEndGate")==0) return base+9;
    if (fieldName[0]=='i' && strcmp(fieldName, "isConnectedOutside")==0) return base+10;
    if (fieldName[0]=='i' && strcmp(fieldName, "isConnectedInside")==0) return base+11;
    if (fieldName[0]=='i' && strcmp(fieldName, "isConnected")==0) return base+12;
    if (fieldName[0]=='i' && strcmp(fieldName, "isPathOK")==0) return base+13;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cGateDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "int",
        "bool",
        "int",
        "bool",
        "cChannel",
        "cGate",
        "cGate",
        "cGate",
        "cGate",
        "bool",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<14) ? fieldTypeStrings[field] : NULL;
}

const char *cGateDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Gate type";
            if (!strcmp(propertyname,"enum")) return "cGate_Type";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Gate id, unique within this module";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"getter")) return "isVector";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this gate is part of a gate vector";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If vector: index of this gate within its gate vector";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Only for simple module input gates, and if message transmission duration is nonzero: whether messages arriving on this gate will be given to the module at the start or the end of the reception";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "Channel object associated with the connection";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The gate this one is connected to -- for output gates this points out of this module, and for input gates it points inside";
            return NULL;
        case 7:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The gate whose \"previousGate\" is this gate -- note that \"previous\" and \"next\" correspond to the direction of messages";
            return NULL;
        case 8:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The last gate in the \"previousGate->previousGate->previousGate...\" chain";
            return NULL;
        case 9:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The last gate in the \"nextGate->nextGate->nextGate...\" chain";
            return NULL;
        case 10:
            if (!strcmp(propertyname,"getter")) return "isConnectedOutside";
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "For an output gate this checks nextGate, and previousGate for an input gate";
            return NULL;
        case 11:
            if (!strcmp(propertyname,"getter")) return "isConnectedInside";
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "For an input gate this checks nextGate, and previousGate for an output gate";
            return NULL;
        case 12:
            if (!strcmp(propertyname,"getter")) return "isConnected";
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "Whether the gate is fully connected -- both inside and outside for a compound module gate, and outside for a simple module gate";
            return NULL;
        case 13:
            if (!strcmp(propertyname,"getter")) return "isPathOK";
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The chain of connections is OK if it starts and ends at a simple module";
            return NULL;
        default: return NULL;
    }
}

int cGateDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cGate *pp = (cGate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cGateDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cGate *pp = (cGate *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return long2string(pp->getId());
        case 2: return bool2string(pp->isVector());
        case 3: return long2string(pp->getIndex());
        case 4: return bool2string(pp->getDeliverOnReceptionStart());
        case 5: {std::stringstream out; out << pp->getChannel(); return out.str();}
        case 6: {std::stringstream out; out << pp->getPreviousGate(); return out.str();}
        case 7: {std::stringstream out; out << pp->getNextGate(); return out.str();}
        case 8: {std::stringstream out; out << pp->getPathStartGate(); return out.str();}
        case 9: {std::stringstream out; out << pp->getPathEndGate(); return out.str();}
        case 10: return bool2string(pp->isConnectedOutside());
        case 11: return bool2string(pp->isConnectedInside());
        case 12: return bool2string(pp->isConnected());
        case 13: return bool2string(pp->isPathOK());
        default: return "";
    }
}

bool cGateDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cGate *pp = (cGate *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cGateDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        "cChannel",
        "cGate",
        "cGate",
        "cGate",
        "cGate",
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<14) ? fieldStructNames[field] : NULL;
}

void *cGateDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cGate *pp = (cGate *)object; (void)pp;
    switch (field) {
        case 5: return (void *)static_cast<cObject *>(pp->getChannel()); break;
        case 6: return (void *)static_cast<cObject *>(pp->getPreviousGate()); break;
        case 7: return (void *)static_cast<cObject *>(pp->getNextGate()); break;
        case 8: return (void *)static_cast<cObject *>(pp->getPathStartGate()); break;
        case 9: return (void *)static_cast<cObject *>(pp->getPathEndGate()); break;
        default: return NULL;
    }
}

class cArrayDescriptor : public cClassDescriptor
{
  public:
    cArrayDescriptor();
    virtual ~cArrayDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cArrayDescriptor);

cArrayDescriptor::cArrayDescriptor() : cClassDescriptor("cArray", "cOwnedObject")
{
}

cArrayDescriptor::~cArrayDescriptor()
{
}

bool cArrayDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cArray *>(obj)!=NULL;
}

const char *cArrayDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "container";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cArrayDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int cArrayDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cArrayDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "takeOwnership",
        "contents",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int cArrayDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "takeOwnership")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cArrayDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "cOwnedObject",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *cArrayDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether the array should own the objects inserted into it";
            if (!strcmp(propertyname,"editable")) return "";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "Objects contained in the array";
            if (!strcmp(propertyname,"sizeGetter")) return "size";
            return NULL;
        default: return NULL;
    }
}

int cArrayDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cArray *pp = (cArray *)object; (void)pp;
    switch (field) {
        case 1: return pp->size();
        default: return 0;
    }
}

std::string cArrayDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cArray *pp = (cArray *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getTakeOwnership());
        case 1: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cArrayDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cArray *pp = (cArray *)object; (void)pp;
    switch (field) {
        case 0: pp->setTakeOwnership(string2bool(value)); return true;
        default: return false;
    }
}

const char *cArrayDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "cOwnedObject",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *cArrayDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cArray *pp = (cArray *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<cObject *>(pp->get(i)); break;
        default: return NULL;
    }
}

class cMessageDescriptor : public cClassDescriptor
{
  public:
    cMessageDescriptor();
    virtual ~cMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cMessageDescriptor);

cMessageDescriptor::cMessageDescriptor() : cClassDescriptor("cMessage", "cOwnedObject")
{
}

cMessageDescriptor::~cMessageDescriptor()
{
}

bool cMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cMessage *>(obj)!=NULL;
}

const char *cMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "message";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 21+basedesc->getFieldCount(object) : 21;
}

unsigned int cMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        0,
        0,
        0,
        0,
        FD_ISEDITABLE,
        0,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        0,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<21) ? fieldTypeFlags[field] : 0;
}

const char *cMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "id",
        "treeId",
        "kind",
        "schedulingPriority",
        "displayString",
        "controlInfo",
        "parList",
        "isScheduled",
        "isSelfMessage",
        "creationTime",
        "sendingTime",
        "arrivalTime",
        "timestamp",
        "senderModuleId",
        "senderGateId",
        "senderModule",
        "senderGate",
        "arrivalModuleId",
        "arrivalGateId",
        "arrivalModule",
        "arrivalGate",
    };
    return (field>=0 && field<21) ? fieldNames[field] : NULL;
}

int cMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "treeId")==0) return base+1;
    if (fieldName[0]=='k' && strcmp(fieldName, "kind")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "schedulingPriority")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "controlInfo")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "parList")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "isScheduled")==0) return base+7;
    if (fieldName[0]=='i' && strcmp(fieldName, "isSelfMessage")==0) return base+8;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "sendingTime")==0) return base+10;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalTime")==0) return base+11;
    if (fieldName[0]=='t' && strcmp(fieldName, "timestamp")==0) return base+12;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderModuleId")==0) return base+13;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderGateId")==0) return base+14;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderModule")==0) return base+15;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderGate")==0) return base+16;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalModuleId")==0) return base+17;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalGateId")==0) return base+18;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalModule")==0) return base+19;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalGate")==0) return base+20;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "long",
        "long",
        "short",
        "short",
        "string",
        "cObject",
        "cArray",
        "bool",
        "bool",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "int",
        "int",
        "cModule",
        "cGate",
        "int",
        "int",
        "cModule",
        "cGate",
    };
    return (field>=0 && field<21) ? fieldTypeStrings[field] : NULL;
}

const char *cMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Automatically assigned unique identifier";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Identifier shared between the message and its copies";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Generic user-settable attribute, usually carries \"type\" or \"role\" or \"category\" of message";
            if (!strcmp(propertyname,"editable")) return "";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Controls order of messages with equal timestamps in FES";
            if (!strcmp(propertyname,"editable")) return "";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Controls appearance of the message in GUI";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Used with protocol stacks: carries extra information when a packet is sent between protocol layers";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "OBSOLETE: use of \"parList\" should be replaced with message subclassing in the few models that still use it";
            return NULL;
        case 7:
            if (!strcmp(propertyname,"getter")) return "isScheduled";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Whether message is currently scheduled/in transit or not";
            return NULL;
        case 8:
            if (!strcmp(propertyname,"getter")) return "isSelfMessage";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Whether message is a self-message, scheduled to be delivered back to the same module at a later time";
            return NULL;
        case 9:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Simulation time the message was created";
            return NULL;
        case 10:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Simulation time of the current or last sending/scheduling of the message";
            return NULL;
        case 11:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Simulation time the message will be/was delivered to the destination module";
            return NULL;
        case 12:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "User-settable timestamp for generic use";
            if (!strcmp(propertyname,"editable")) return "";
            return NULL;
        case 13:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "ID of the module performing the current or last send/schedule operation";
            return NULL;
        case 14:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Module-local ID of the gate on which the message was sent out -- -1==none for self-messages and after \"sendDirect\"";
            return NULL;
        case 15:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"eventlog")) return "fullPath";
            if (!strcmp(propertyname,"hint")) return "ID of the module performing the current or last send/schedule operation";
            return NULL;
        case 16:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"eventlog")) return "fullName";
            if (!strcmp(propertyname,"hint")) return "The gate on which the message was sent out -- NULL for self-messages and after \"sendDirect\"";
            return NULL;
        case 17:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "ID of the arrival module of the current or last sending/scheduling";
            return NULL;
        case 18:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Module-local ID of arrival gate for current or last sending -- -1==none for self-messages";
            return NULL;
        case 19:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"eventlog")) return "fullPath";
            if (!strcmp(propertyname,"hint")) return "Arrival module for current or last sending/scheduling";
            return NULL;
        case 20:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"eventlog")) return "fullName";
            if (!strcmp(propertyname,"hint")) return "Arrival gate for current or last sending -- NULL for self-messages";
            return NULL;
        default: return NULL;
    }
}

int cMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cMessage *pp = (cMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cMessage *pp = (cMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getId());
        case 1: return long2string(pp->getTreeId());
        case 2: return long2string(pp->getKind());
        case 3: return long2string(pp->getSchedulingPriority());
        case 4: return oppstring2string(pp->getDisplayString());
        case 5: {std::stringstream out; out << pp->getControlInfo(); return out.str();}
        case 6: {std::stringstream out; out << pp->getParList(); return out.str();}
        case 7: return bool2string(pp->isScheduled());
        case 8: return bool2string(pp->isSelfMessage());
        case 9: return double2string(pp->getCreationTime());
        case 10: return double2string(pp->getSendingTime());
        case 11: return double2string(pp->getArrivalTime());
        case 12: return double2string(pp->getTimestamp());
        case 13: return long2string(pp->getSenderModuleId());
        case 14: return long2string(pp->getSenderGateId());
        case 15: {std::stringstream out; out << pp->getSenderModule(); return out.str();}
        case 16: {std::stringstream out; out << pp->getSenderGate(); return out.str();}
        case 17: return long2string(pp->getArrivalModuleId());
        case 18: return long2string(pp->getArrivalGateId());
        case 19: {std::stringstream out; out << pp->getArrivalModule(); return out.str();}
        case 20: {std::stringstream out; out << pp->getArrivalGate(); return out.str();}
        default: return "";
    }
}

bool cMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cMessage *pp = (cMessage *)object; (void)pp;
    switch (field) {
        case 2: pp->setKind(string2long(value)); return true;
        case 3: pp->setSchedulingPriority(string2long(value)); return true;
        case 12: pp->setTimestamp(string2double(value)); return true;
        default: return false;
    }
}

const char *cMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        "cObject",
        "cArray",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        "cModule",
        "cGate",
        NULL,
        NULL,
        "cModule",
        "cGate",
    };
    return (field>=0 && field<21) ? fieldStructNames[field] : NULL;
}

void *cMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cMessage *pp = (cMessage *)object; (void)pp;
    switch (field) {
        case 5: return (void *)static_cast<cObject *>(pp->getControlInfo()); break;
        case 6: return (void *)static_cast<cObject *>(&pp->getParList()); break;
        case 15: return (void *)static_cast<cObject *>(pp->getSenderModule()); break;
        case 16: return (void *)static_cast<cObject *>(pp->getSenderGate()); break;
        case 19: return (void *)static_cast<cObject *>(pp->getArrivalModule()); break;
        case 20: return (void *)static_cast<cObject *>(pp->getArrivalGate()); break;
        default: return NULL;
    }
}

class cPacketDescriptor : public cClassDescriptor
{
  public:
    cPacketDescriptor();
    virtual ~cPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cPacketDescriptor);

cPacketDescriptor::cPacketDescriptor() : cClassDescriptor("cPacket", "cMessage")
{
}

cPacketDescriptor::~cPacketDescriptor()
{
}

bool cPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cPacket *>(obj)!=NULL;
}

const char *cPacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "packet";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int cPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        0,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *cPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "bitLength",
        "byteLength",
        "hasBitError",
        "encapsulatedPacket",
        "isReceptionStart",
        "duration",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int cPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitLength")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "byteLength")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hasBitError")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "encapsulatedPacket")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "isReceptionStart")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int64",
        "int64",
        "bool",
        "cPacket",
        "bool",
        "simtime_t",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *cPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Simulated length of the message in bits, affects transmission time and probability of bit errors when sent through a channel";
            if (!strcmp(propertyname,"editable")) return "";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Length in bytes, i.e. length in bits divided by eight";
            if (!strcmp(propertyname,"editable")) return "";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"getter")) return "hasBitError";
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Indicates that a bit error occurred when the message was sent through a channel with nonzero bit error rate";
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"setter")) return "setBitError";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"hint")) return "Used with protocol stacks: stores an encapsulated higher-layer packet";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"getter")) return "isReceptionStart";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "When duration is nonzero: whether this message represents the start or the end of the frame reception";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Transmission time over a channel with datarate";
            return NULL;
        default: return NULL;
    }
}

int cPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cPacket *pp = (cPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cPacket *pp = (cPacket *)object; (void)pp;
    switch (field) {
        case 0: return int642string(pp->getBitLength());
        case 1: return int642string(pp->getByteLength());
        case 2: return bool2string(pp->hasBitError());
        case 3: {std::stringstream out; out << pp->getEncapsulatedPacket(); return out.str();}
        case 4: return bool2string(pp->isReceptionStart());
        case 5: return double2string(pp->getDuration());
        default: return "";
    }
}

bool cPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cPacket *pp = (cPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setBitLength(string2int64(value)); return true;
        case 1: pp->setByteLength(string2int64(value)); return true;
        case 2: pp->setBitError(string2bool(value)); return true;
        default: return false;
    }
}

const char *cPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        "cPacket",
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *cPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cPacket *pp = (cPacket *)object; (void)pp;
    switch (field) {
        case 3: return (void *)static_cast<cObject *>(pp->getEncapsulatedPacket()); break;
        default: return NULL;
    }
}

class cStatisticDescriptor : public cClassDescriptor
{
  public:
    cStatisticDescriptor();
    virtual ~cStatisticDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cStatisticDescriptor);

cStatisticDescriptor::cStatisticDescriptor() : cClassDescriptor("cStatistic", "cOwnedObject")
{
}

cStatisticDescriptor::~cStatisticDescriptor()
{
}

bool cStatisticDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cStatistic *>(obj)!=NULL;
}

const char *cStatisticDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "statistic";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cStatisticDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount(object) : 9;
}

unsigned int cStatisticDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *cStatisticDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "count",
        "weights",
        "sum",
        "sqrSum",
        "min",
        "max",
        "mean",
        "stddev",
        "variance",
    };
    return (field>=0 && field<9) ? fieldNames[field] : NULL;
}

int cStatisticDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "count")==0) return base+0;
    if (fieldName[0]=='w' && strcmp(fieldName, "weights")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sum")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sqrSum")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "min")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "max")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "mean")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "stddev")==0) return base+7;
    if (fieldName[0]=='v' && strcmp(fieldName, "variance")==0) return base+8;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cStatisticDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "long",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : NULL;
}

const char *cStatisticDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Number of observations collected so far";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Sum of weights, which equals the number of observations in the unweighted case";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Sum of observations";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"hint")) return "Sum of squares of the observations";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"hint")) return "Minimum of the observations";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"hint")) return "Maximum of the observations";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"hint")) return "Mean of the observations";
            return NULL;
        case 7:
            if (!strcmp(propertyname,"hint")) return "Standard deviation of the observations";
            return NULL;
        case 8:
            if (!strcmp(propertyname,"hint")) return "Variance of the observations";
            return NULL;
        default: return NULL;
    }
}

int cStatisticDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cStatistic *pp = (cStatistic *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cStatisticDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cStatistic *pp = (cStatistic *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCount());
        case 1: return double2string(pp->getWeights());
        case 2: return double2string(pp->getSum());
        case 3: return double2string(pp->getSqrSum());
        case 4: return double2string(pp->getMin());
        case 5: return double2string(pp->getMax());
        case 6: return double2string(pp->getMean());
        case 7: return double2string(pp->getStddev());
        case 8: return double2string(pp->getVariance());
        default: return "";
    }
}

bool cStatisticDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cStatistic *pp = (cStatistic *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cStatisticDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<9) ? fieldStructNames[field] : NULL;
}

void *cStatisticDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cStatistic *pp = (cStatistic *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cStdDevDescriptor : public cClassDescriptor
{
  public:
    cStdDevDescriptor();
    virtual ~cStdDevDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cStdDevDescriptor);

cStdDevDescriptor::cStdDevDescriptor() : cClassDescriptor("cStdDev", "cStatistic")
{
}

cStdDevDescriptor::~cStdDevDescriptor()
{
}

bool cStdDevDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cStdDev *>(obj)!=NULL;
}

const char *cStdDevDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cStdDevDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cStdDevDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cStdDevDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cStdDevDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cStdDevDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cStdDevDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cStdDevDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cStdDev *pp = (cStdDev *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cStdDevDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cStdDev *pp = (cStdDev *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cStdDevDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cStdDev *pp = (cStdDev *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cStdDevDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cStdDevDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cStdDev *pp = (cStdDev *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cWeightedStdDevDescriptor : public cClassDescriptor
{
  public:
    cWeightedStdDevDescriptor();
    virtual ~cWeightedStdDevDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cWeightedStdDevDescriptor);

cWeightedStdDevDescriptor::cWeightedStdDevDescriptor() : cClassDescriptor("cWeightedStdDev", "cStdDev")
{
}

cWeightedStdDevDescriptor::~cWeightedStdDevDescriptor()
{
}

bool cWeightedStdDevDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cWeightedStdDev *>(obj)!=NULL;
}

const char *cWeightedStdDevDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cWeightedStdDevDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cWeightedStdDevDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cWeightedStdDevDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cWeightedStdDevDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cWeightedStdDevDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cWeightedStdDevDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cWeightedStdDevDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cWeightedStdDev *pp = (cWeightedStdDev *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cWeightedStdDevDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cWeightedStdDev *pp = (cWeightedStdDev *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cWeightedStdDevDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cWeightedStdDev *pp = (cWeightedStdDev *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cWeightedStdDevDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cWeightedStdDevDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cWeightedStdDev *pp = (cWeightedStdDev *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cDensityEstBaseDescriptor : public cClassDescriptor
{
  public:
    cDensityEstBaseDescriptor();
    virtual ~cDensityEstBaseDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cDensityEstBaseDescriptor);

cDensityEstBaseDescriptor::cDensityEstBaseDescriptor() : cClassDescriptor("cDensityEstBase", "cStdDev")
{
}

cDensityEstBaseDescriptor::~cDensityEstBaseDescriptor()
{
}

bool cDensityEstBaseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cDensityEstBase *>(obj)!=NULL;
}

const char *cDensityEstBaseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cDensityEstBaseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int cDensityEstBaseDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *cDensityEstBaseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "isTransformed",
        "underflowCell",
        "overflowCell",
        "numCells",
        "cellInfo",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int cDensityEstBaseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isTransformed")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "underflowCell")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "overflowCell")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numCells")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "cellInfo")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cDensityEstBaseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "unsigned long",
        "unsigned long",
        "int",
        "cDensityEstBase_Cell",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *cDensityEstBaseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isTransformed";
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "If false, the object is still collecting initial observations to be used for laying out histogram cells";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "Number of observations below the first histogram cell";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "Number of observations above the last histogram cell";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "Number of cells in the histogram";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"getter")) return "internalGetCellInfo";
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "Histogram cell bounds, observation count in the cell, and density estimate in the cell";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumCells";
            return NULL;
        default: return NULL;
    }
}

int cDensityEstBaseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cDensityEstBase *pp = (cDensityEstBase *)object; (void)pp;
    switch (field) {
        case 4: return pp->getNumCells();
        default: return 0;
    }
}

std::string cDensityEstBaseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cDensityEstBase *pp = (cDensityEstBase *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isTransformed());
        case 1: return ulong2string(pp->getUnderflowCell());
        case 2: return ulong2string(pp->getOverflowCell());
        case 3: return long2string(pp->getNumCells());
        case 4: {std::stringstream out; out << pp->internalGetCellInfo(i); return out.str();}
        default: return "";
    }
}

bool cDensityEstBaseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cDensityEstBase *pp = (cDensityEstBase *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDensityEstBaseDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        "cDensityEstBase_Cell",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *cDensityEstBaseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cDensityEstBase *pp = (cDensityEstBase *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->internalGetCellInfo(i)); break;
        default: return NULL;
    }
}

class cHistogramBaseDescriptor : public cClassDescriptor
{
  public:
    cHistogramBaseDescriptor();
    virtual ~cHistogramBaseDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cHistogramBaseDescriptor);

cHistogramBaseDescriptor::cHistogramBaseDescriptor() : cClassDescriptor("cHistogramBase", "cDensityEstBase")
{
}

cHistogramBaseDescriptor::~cHistogramBaseDescriptor()
{
}

bool cHistogramBaseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cHistogramBase *>(obj)!=NULL;
}

const char *cHistogramBaseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cHistogramBaseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cHistogramBaseDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cHistogramBaseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cHistogramBaseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cHistogramBaseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cHistogramBaseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cHistogramBaseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cHistogramBase *pp = (cHistogramBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cHistogramBaseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cHistogramBase *pp = (cHistogramBase *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cHistogramBaseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cHistogramBase *pp = (cHistogramBase *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cHistogramBaseDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cHistogramBaseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cHistogramBase *pp = (cHistogramBase *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cHistogramDescriptor : public cClassDescriptor
{
  public:
    cHistogramDescriptor();
    virtual ~cHistogramDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cHistogramDescriptor);

cHistogramDescriptor::cHistogramDescriptor() : cClassDescriptor("cHistogram", "cHistogramBase")
{
}

cHistogramDescriptor::~cHistogramDescriptor()
{
}

bool cHistogramDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cHistogram *>(obj)!=NULL;
}

const char *cHistogramDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cHistogramDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cHistogramDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cHistogramDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cHistogramDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cHistogramDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cHistogramDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cHistogramDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cHistogram *pp = (cHistogram *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cHistogramDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cHistogram *pp = (cHistogram *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cHistogramDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cHistogram *pp = (cHistogram *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cHistogramDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cHistogramDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cHistogram *pp = (cHistogram *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cVarHistogramDescriptor : public cClassDescriptor
{
  public:
    cVarHistogramDescriptor();
    virtual ~cVarHistogramDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cVarHistogramDescriptor);

cVarHistogramDescriptor::cVarHistogramDescriptor() : cClassDescriptor("cVarHistogram", "cHistogramBase")
{
}

cVarHistogramDescriptor::~cVarHistogramDescriptor()
{
}

bool cVarHistogramDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cVarHistogram *>(obj)!=NULL;
}

const char *cVarHistogramDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cVarHistogramDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cVarHistogramDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cVarHistogramDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cVarHistogramDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cVarHistogramDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cVarHistogramDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cVarHistogramDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cVarHistogram *pp = (cVarHistogram *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cVarHistogramDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cVarHistogram *pp = (cVarHistogram *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cVarHistogramDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cVarHistogram *pp = (cVarHistogram *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cVarHistogramDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cVarHistogramDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cVarHistogram *pp = (cVarHistogram *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cLongHistogramDescriptor : public cClassDescriptor
{
  public:
    cLongHistogramDescriptor();
    virtual ~cLongHistogramDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cLongHistogramDescriptor);

cLongHistogramDescriptor::cLongHistogramDescriptor() : cClassDescriptor("cLongHistogram", "cHistogram")
{
}

cLongHistogramDescriptor::~cLongHistogramDescriptor()
{
}

bool cLongHistogramDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cLongHistogram *>(obj)!=NULL;
}

const char *cLongHistogramDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cLongHistogramDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cLongHistogramDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cLongHistogramDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cLongHistogramDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cLongHistogramDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cLongHistogramDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cLongHistogramDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cLongHistogram *pp = (cLongHistogram *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cLongHistogramDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cLongHistogram *pp = (cLongHistogram *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cLongHistogramDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cLongHistogram *pp = (cLongHistogram *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cLongHistogramDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cLongHistogramDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cLongHistogram *pp = (cLongHistogram *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cDoubleHistogramDescriptor : public cClassDescriptor
{
  public:
    cDoubleHistogramDescriptor();
    virtual ~cDoubleHistogramDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cDoubleHistogramDescriptor);

cDoubleHistogramDescriptor::cDoubleHistogramDescriptor() : cClassDescriptor("cDoubleHistogram", "cHistogram")
{
}

cDoubleHistogramDescriptor::~cDoubleHistogramDescriptor()
{
}

bool cDoubleHistogramDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cDoubleHistogram *>(obj)!=NULL;
}

const char *cDoubleHistogramDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cDoubleHistogramDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cDoubleHistogramDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cDoubleHistogramDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cDoubleHistogramDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cDoubleHistogramDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cDoubleHistogramDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cDoubleHistogramDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cDoubleHistogram *pp = (cDoubleHistogram *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cDoubleHistogramDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cDoubleHistogram *pp = (cDoubleHistogram *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cDoubleHistogramDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cDoubleHistogram *pp = (cDoubleHistogram *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDoubleHistogramDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cDoubleHistogramDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cDoubleHistogram *pp = (cDoubleHistogram *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cKSplitDescriptor : public cClassDescriptor
{
  public:
    cKSplitDescriptor();
    virtual ~cKSplitDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cKSplitDescriptor);

cKSplitDescriptor::cKSplitDescriptor() : cClassDescriptor("cKSplit", "cDensityEstBase")
{
}

cKSplitDescriptor::~cKSplitDescriptor()
{
}

bool cKSplitDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cKSplit *>(obj)!=NULL;
}

const char *cKSplitDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cKSplitDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cKSplitDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cKSplitDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cKSplitDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cKSplitDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cKSplitDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cKSplitDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cKSplit *pp = (cKSplit *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cKSplitDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cKSplit *pp = (cKSplit *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cKSplitDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cKSplit *pp = (cKSplit *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cKSplitDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cKSplitDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cKSplit *pp = (cKSplit *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cPSquareDescriptor : public cClassDescriptor
{
  public:
    cPSquareDescriptor();
    virtual ~cPSquareDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cPSquareDescriptor);

cPSquareDescriptor::cPSquareDescriptor() : cClassDescriptor("cPSquare", "cDensityEstBase")
{
}

cPSquareDescriptor::~cPSquareDescriptor()
{
}

bool cPSquareDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cPSquare *>(obj)!=NULL;
}

const char *cPSquareDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cPSquareDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cPSquareDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cPSquareDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cPSquareDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cPSquareDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cPSquareDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cPSquareDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cPSquare *pp = (cPSquare *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPSquareDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cPSquare *pp = (cPSquare *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cPSquareDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cPSquare *pp = (cPSquare *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPSquareDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cPSquareDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cPSquare *pp = (cPSquare *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cTransientDetectionDescriptor : public cClassDescriptor
{
  public:
    cTransientDetectionDescriptor();
    virtual ~cTransientDetectionDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cTransientDetectionDescriptor);

cTransientDetectionDescriptor::cTransientDetectionDescriptor() : cClassDescriptor("cTransientDetection", "cOwnedObject")
{
}

cTransientDetectionDescriptor::~cTransientDetectionDescriptor()
{
}

bool cTransientDetectionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cTransientDetection *>(obj)!=NULL;
}

const char *cTransientDetectionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cTransientDetectionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cTransientDetectionDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cTransientDetectionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cTransientDetectionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cTransientDetectionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cTransientDetectionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cTransientDetectionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cTransientDetection *pp = (cTransientDetection *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTransientDetectionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cTransientDetection *pp = (cTransientDetection *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cTransientDetectionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cTransientDetection *pp = (cTransientDetection *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTransientDetectionDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cTransientDetectionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cTransientDetection *pp = (cTransientDetection *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cAccuracyDetectionDescriptor : public cClassDescriptor
{
  public:
    cAccuracyDetectionDescriptor();
    virtual ~cAccuracyDetectionDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cAccuracyDetectionDescriptor);

cAccuracyDetectionDescriptor::cAccuracyDetectionDescriptor() : cClassDescriptor("cAccuracyDetection", "cOwnedObject")
{
}

cAccuracyDetectionDescriptor::~cAccuracyDetectionDescriptor()
{
}

bool cAccuracyDetectionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cAccuracyDetection *>(obj)!=NULL;
}

const char *cAccuracyDetectionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cAccuracyDetectionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cAccuracyDetectionDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cAccuracyDetectionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cAccuracyDetectionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cAccuracyDetectionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cAccuracyDetectionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cAccuracyDetectionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cAccuracyDetection *pp = (cAccuracyDetection *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cAccuracyDetectionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cAccuracyDetection *pp = (cAccuracyDetection *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cAccuracyDetectionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cAccuracyDetection *pp = (cAccuracyDetection *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cAccuracyDetectionDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cAccuracyDetectionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cAccuracyDetection *pp = (cAccuracyDetection *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cTDExpandingWindowsDescriptor : public cClassDescriptor
{
  public:
    cTDExpandingWindowsDescriptor();
    virtual ~cTDExpandingWindowsDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cTDExpandingWindowsDescriptor);

cTDExpandingWindowsDescriptor::cTDExpandingWindowsDescriptor() : cClassDescriptor("cTDExpandingWindows", "cTransientDetection")
{
}

cTDExpandingWindowsDescriptor::~cTDExpandingWindowsDescriptor()
{
}

bool cTDExpandingWindowsDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cTDExpandingWindows *>(obj)!=NULL;
}

const char *cTDExpandingWindowsDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cTDExpandingWindowsDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cTDExpandingWindowsDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cTDExpandingWindowsDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cTDExpandingWindowsDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cTDExpandingWindowsDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cTDExpandingWindowsDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cTDExpandingWindowsDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cTDExpandingWindows *pp = (cTDExpandingWindows *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTDExpandingWindowsDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cTDExpandingWindows *pp = (cTDExpandingWindows *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cTDExpandingWindowsDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cTDExpandingWindows *pp = (cTDExpandingWindows *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTDExpandingWindowsDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cTDExpandingWindowsDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cTDExpandingWindows *pp = (cTDExpandingWindows *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cADByStddevDescriptor : public cClassDescriptor
{
  public:
    cADByStddevDescriptor();
    virtual ~cADByStddevDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cADByStddevDescriptor);

cADByStddevDescriptor::cADByStddevDescriptor() : cClassDescriptor("cADByStddev", "cAccuracyDetection")
{
}

cADByStddevDescriptor::~cADByStddevDescriptor()
{
}

bool cADByStddevDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cADByStddev *>(obj)!=NULL;
}

const char *cADByStddevDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cADByStddevDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cADByStddevDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cADByStddevDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cADByStddevDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cADByStddevDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cADByStddevDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cADByStddevDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cADByStddev *pp = (cADByStddev *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cADByStddevDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cADByStddev *pp = (cADByStddev *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cADByStddevDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cADByStddev *pp = (cADByStddev *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cADByStddevDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cADByStddevDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cADByStddev *pp = (cADByStddev *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cExpressionDescriptor : public cClassDescriptor
{
  public:
    cExpressionDescriptor();
    virtual ~cExpressionDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cExpressionDescriptor);

cExpressionDescriptor::cExpressionDescriptor() : cClassDescriptor("cExpression", "cObject")
{
}

cExpressionDescriptor::~cExpressionDescriptor()
{
}

bool cExpressionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cExpression *>(obj)!=NULL;
}

const char *cExpressionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cExpressionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cExpressionDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cExpressionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "str",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cExpressionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "str")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cExpressionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cExpressionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "str";
            return NULL;
        default: return NULL;
    }
}

int cExpressionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cExpression *pp = (cExpression *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cExpressionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cExpression *pp = (cExpression *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        default: return "";
    }
}

bool cExpressionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cExpression *pp = (cExpression *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cExpressionDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cExpressionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cExpression *pp = (cExpression *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cFSMDescriptor : public cClassDescriptor
{
  public:
    cFSMDescriptor();
    virtual ~cFSMDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cFSMDescriptor);

cFSMDescriptor::cFSMDescriptor() : cClassDescriptor("cFSM", "cOwnedObject")
{
}

cFSMDescriptor::~cFSMDescriptor()
{
}

bool cFSMDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cFSM *>(obj)!=NULL;
}

const char *cFSMDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cFSMDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int cFSMDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cFSMDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "state",
        "stateName",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int cFSMDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "state")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stateName")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cFSMDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *cFSMDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Numeric code of the state the FSM is currently in";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Name of the current FSM state";
            return NULL;
        default: return NULL;
    }
}

int cFSMDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cFSM *pp = (cFSM *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cFSMDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cFSM *pp = (cFSM *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getState());
        case 1: return oppstring2string(pp->getStateName());
        default: return "";
    }
}

bool cFSMDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cFSM *pp = (cFSM *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cFSMDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *cFSMDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cFSM *pp = (cFSM *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cNEDMathFunctionDescriptor : public cClassDescriptor
{
  public:
    cNEDMathFunctionDescriptor();
    virtual ~cNEDMathFunctionDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cNEDMathFunctionDescriptor);

cNEDMathFunctionDescriptor::cNEDMathFunctionDescriptor() : cClassDescriptor("cNEDMathFunction", "cNoncopyableOwnedObject")
{
}

cNEDMathFunctionDescriptor::~cNEDMathFunctionDescriptor()
{
}

bool cNEDMathFunctionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cNEDMathFunction *>(obj)!=NULL;
}

const char *cNEDMathFunctionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cNEDMathFunctionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int cNEDMathFunctionDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cNEDMathFunctionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "category",
        "description",
        "numArgs",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int cNEDMathFunctionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "category")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "description")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "numArgs")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cNEDMathFunctionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *cNEDMathFunctionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Function category";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Number of \"double\" parameters this function takes";
            return NULL;
        default: return NULL;
    }
}

int cNEDMathFunctionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cNEDMathFunction *pp = (cNEDMathFunction *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cNEDMathFunctionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cNEDMathFunction *pp = (cNEDMathFunction *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getCategory());
        case 1: return oppstring2string(pp->getDescription());
        case 2: return long2string(pp->getNumArgs());
        default: return "";
    }
}

bool cNEDMathFunctionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cNEDMathFunction *pp = (cNEDMathFunction *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cNEDMathFunctionDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *cNEDMathFunctionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cNEDMathFunction *pp = (cNEDMathFunction *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cNEDFunctionDescriptor : public cClassDescriptor
{
  public:
    cNEDFunctionDescriptor();
    virtual ~cNEDFunctionDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cNEDFunctionDescriptor);

cNEDFunctionDescriptor::cNEDFunctionDescriptor() : cClassDescriptor("cNEDFunction", "cNoncopyableOwnedObject")
{
}

cNEDFunctionDescriptor::~cNEDFunctionDescriptor()
{
}

bool cNEDFunctionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cNEDFunction *>(obj)!=NULL;
}

const char *cNEDFunctionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cNEDFunctionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int cNEDFunctionDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        FD_ISARRAY,
        0,
        0,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *cNEDFunctionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "signature",
        "category",
        "description",
        "returnType",
        "argType",
        "minArgs",
        "maxArgs",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int cNEDFunctionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "signature")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "category")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "description")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "returnType")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "argType")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "minArgs")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxArgs")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cNEDFunctionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "char",
        "char",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *cNEDFunctionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Argument types and return value";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Function category";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"sizeGetter")) return "getMaxArgs";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"hint")) return "Number of mandatory arguments";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"hint")) return "Maximum number of arguments";
            return NULL;
        default: return NULL;
    }
}

int cNEDFunctionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cNEDFunction *pp = (cNEDFunction *)object; (void)pp;
    switch (field) {
        case 4: return pp->getMaxArgs();
        default: return 0;
    }
}

std::string cNEDFunctionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cNEDFunction *pp = (cNEDFunction *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSignature());
        case 1: return oppstring2string(pp->getCategory());
        case 2: return oppstring2string(pp->getDescription());
        case 3: return long2string(pp->getReturnType());
        case 4: return long2string(pp->getArgType(i));
        case 5: return long2string(pp->getMinArgs());
        case 6: return long2string(pp->getMaxArgs());
        default: return "";
    }
}

bool cNEDFunctionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cNEDFunction *pp = (cNEDFunction *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cNEDFunctionDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *cNEDFunctionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cNEDFunction *pp = (cNEDFunction *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cOutVectorDescriptor : public cClassDescriptor
{
  public:
    cOutVectorDescriptor();
    virtual ~cOutVectorDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cOutVectorDescriptor);

cOutVectorDescriptor::cOutVectorDescriptor() : cClassDescriptor("cOutVector", "cNoncopyableOwnedObject")
{
}

cOutVectorDescriptor::~cOutVectorDescriptor()
{
}

bool cOutVectorDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cOutVector *>(obj)!=NULL;
}

const char *cOutVectorDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "outvector";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cOutVectorDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int cOutVectorDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        0,
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cOutVectorDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "isEnabled",
        "valuesReceived",
        "valuesStored",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int cOutVectorDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isEnabled")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "valuesReceived")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "valuesStored")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cOutVectorDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "long",
        "long",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *cOutVectorDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isEnabled";
            if (!strcmp(propertyname,"hint")) return "If disabled, values passed to this object to record are simply discarded";
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"setter")) return "setEnabled";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Number of values passed to this object to record";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Number of values actually stored on the disk";
            return NULL;
        default: return NULL;
    }
}

int cOutVectorDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cOutVector *pp = (cOutVector *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cOutVectorDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cOutVector *pp = (cOutVector *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isEnabled());
        case 1: return long2string(pp->getValuesReceived());
        case 2: return long2string(pp->getValuesStored());
        default: return "";
    }
}

bool cOutVectorDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cOutVector *pp = (cOutVector *)object; (void)pp;
    switch (field) {
        case 0: pp->setEnabled(string2bool(value)); return true;
        default: return false;
    }
}

const char *cOutVectorDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *cOutVectorDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cOutVector *pp = (cOutVector *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cParDescriptor : public cClassDescriptor
{
  public:
    cParDescriptor();
    virtual ~cParDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cParDescriptor);

cParDescriptor::cParDescriptor() : cClassDescriptor("cPar", "cObject")
{
}

cParDescriptor::~cParDescriptor()
{
}

bool cParDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cPar *>(obj)!=NULL;
}

const char *cParDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "param";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cParDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int cParDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *cParDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "value",
        "type",
        "unit",
        "isNumeric",
        "isVolatile",
        "isExpression",
        "isShared",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int cParDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "unit")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "isNumeric")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "isVolatile")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "isExpression")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "isShared")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cParDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "char",
        "string",
        "bool",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *cParDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "str";
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"setter")) return "parse";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Parameter type";
            if (!strcmp(propertyname,"enum")) return "cPar_Type";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "For long and double types only";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"getter")) return "isNumeric";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether parameter type is numeric, i.e. double or long";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"getter")) return "isVolatile";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether parameter was declared volatile in the NED file";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"getter")) return "isExpression";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether parameter value is a constant or an expression";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"getter")) return "isShared";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether storage could be optimized by several modules sharing the same parameter value object";
            return NULL;
        default: return NULL;
    }
}

int cParDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cPar *pp = (cPar *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cParDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cPar *pp = (cPar *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        case 1: return long2string(pp->getType());
        case 2: return oppstring2string(pp->getUnit());
        case 3: return bool2string(pp->isNumeric());
        case 4: return bool2string(pp->isVolatile());
        case 5: return bool2string(pp->isExpression());
        case 6: return bool2string(pp->isShared());
        default: return "";
    }
}

bool cParDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cPar *pp = (cPar *)object; (void)pp;
    switch (field) {
        case 0: pp->parse((value)); return true;
        default: return false;
    }
}

const char *cParDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *cParDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cPar *pp = (cPar *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cMsgParDescriptor : public cClassDescriptor
{
  public:
    cMsgParDescriptor();
    virtual ~cMsgParDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cMsgParDescriptor);

cMsgParDescriptor::cMsgParDescriptor() : cClassDescriptor("cMsgPar", "cOwnedObject")
{
}

cMsgParDescriptor::~cMsgParDescriptor()
{
}

bool cMsgParDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cMsgPar *>(obj)!=NULL;
}

const char *cMsgParDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cMsgParDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int cMsgParDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        0,
        0,
        0,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *cMsgParDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "value",
        "type",
        "isNumeric",
        "isConstant",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int cMsgParDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isNumeric")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "isConstant")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cMsgParDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "char",
        "bool",
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *cMsgParDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "str";
            if (!strcmp(propertyname,"hint")) return "Parameter value";
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"setter")) return "parse";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Parameter type";
            if (!strcmp(propertyname,"enum")) return "cPar_Type";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"getter")) return "isNumeric";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether parameter is of numeric type";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"getter")) return "isConstant";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether the parameter has a constant value";
            return NULL;
        default: return NULL;
    }
}

int cMsgParDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cMsgPar *pp = (cMsgPar *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cMsgParDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cMsgPar *pp = (cMsgPar *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        case 1: return long2string(pp->getType());
        case 2: return bool2string(pp->isNumeric());
        case 3: return bool2string(pp->isConstant());
        default: return "";
    }
}

bool cMsgParDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cMsgPar *pp = (cMsgPar *)object; (void)pp;
    switch (field) {
        case 0: pp->parse((value)); return true;
        default: return false;
    }
}

const char *cMsgParDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *cMsgParDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cMsgPar *pp = (cMsgPar *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cLinkedListDescriptor : public cClassDescriptor
{
  public:
    cLinkedListDescriptor();
    virtual ~cLinkedListDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cLinkedListDescriptor);

cLinkedListDescriptor::cLinkedListDescriptor() : cClassDescriptor("cLinkedList", "cOwnedObject")
{
}

cLinkedListDescriptor::~cLinkedListDescriptor()
{
}

bool cLinkedListDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cLinkedList *>(obj)!=NULL;
}

const char *cLinkedListDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "queue";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cLinkedListDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cLinkedListDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cLinkedListDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "length",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cLinkedListDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cLinkedListDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cLinkedListDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Number of items contained";
            return NULL;
        default: return NULL;
    }
}

int cLinkedListDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cLinkedList *pp = (cLinkedList *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cLinkedListDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cLinkedList *pp = (cLinkedList *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getLength());
        default: return "";
    }
}

bool cLinkedListDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cLinkedList *pp = (cLinkedList *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cLinkedListDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cLinkedListDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cLinkedList *pp = (cLinkedList *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cMessageHeapDescriptor : public cClassDescriptor
{
  public:
    cMessageHeapDescriptor();
    virtual ~cMessageHeapDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cMessageHeapDescriptor);

cMessageHeapDescriptor::cMessageHeapDescriptor() : cClassDescriptor("cMessageHeap", "cOwnedObject")
{
}

cMessageHeapDescriptor::~cMessageHeapDescriptor()
{
}

bool cMessageHeapDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cMessageHeap *>(obj)!=NULL;
}

const char *cMessageHeapDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "container";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cMessageHeapDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int cMessageHeapDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cMessageHeapDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "length",
        "messages",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int cMessageHeapDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messages")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cMessageHeapDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "cMessage",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *cMessageHeapDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Number of items contained";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"getter")) return "peek";
            if (!strcmp(propertyname,"hint")) return "Self-messages currently scheduled and messages currently in transit";
            if (!strcmp(propertyname,"sizeGetter")) return "getLength";
            return NULL;
        default: return NULL;
    }
}

int cMessageHeapDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cMessageHeap *pp = (cMessageHeap *)object; (void)pp;
    switch (field) {
        case 1: return pp->getLength();
        default: return 0;
    }
}

std::string cMessageHeapDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cMessageHeap *pp = (cMessageHeap *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getLength());
        case 1: {std::stringstream out; out << pp->peek(i); return out.str();}
        default: return "";
    }
}

bool cMessageHeapDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cMessageHeap *pp = (cMessageHeap *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cMessageHeapDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "cMessage",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *cMessageHeapDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cMessageHeap *pp = (cMessageHeap *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<cObject *>(pp->peek(i)); break;
        default: return NULL;
    }
}

class cQueueDescriptor : public cClassDescriptor
{
  public:
    cQueueDescriptor();
    virtual ~cQueueDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cQueueDescriptor);

cQueueDescriptor::cQueueDescriptor() : cClassDescriptor("cQueue", "cOwnedObject")
{
}

cQueueDescriptor::~cQueueDescriptor()
{
}

bool cQueueDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cQueue *>(obj)!=NULL;
}

const char *cQueueDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "queue";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cQueueDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int cQueueDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cQueueDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "takeOwnership",
        "length",
        "contents",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int cQueueDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "takeOwnership")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cQueueDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "int",
        "cOwnedObject",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *cQueueDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether the queue should own the objects inserted into it";
            if (!strcmp(propertyname,"editable")) return "";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Number of items in the queue";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "Queue contents";
            if (!strcmp(propertyname,"sizeGetter")) return "getLength";
            return NULL;
        default: return NULL;
    }
}

int cQueueDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cQueue *pp = (cQueue *)object; (void)pp;
    switch (field) {
        case 2: return pp->getLength();
        default: return 0;
    }
}

std::string cQueueDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cQueue *pp = (cQueue *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getTakeOwnership());
        case 1: return long2string(pp->getLength());
        case 2: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cQueueDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cQueue *pp = (cQueue *)object; (void)pp;
    switch (field) {
        case 0: pp->setTakeOwnership(string2bool(value)); return true;
        default: return false;
    }
}

const char *cQueueDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        "cOwnedObject",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *cQueueDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cQueue *pp = (cQueue *)object; (void)pp;
    switch (field) {
        case 2: return (void *)static_cast<cObject *>(pp->get(i)); break;
        default: return NULL;
    }
}

class cPacketQueueDescriptor : public cClassDescriptor
{
  public:
    cPacketQueueDescriptor();
    virtual ~cPacketQueueDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cPacketQueueDescriptor);

cPacketQueueDescriptor::cPacketQueueDescriptor() : cClassDescriptor("cPacketQueue", "cQueue")
{
}

cPacketQueueDescriptor::~cPacketQueueDescriptor()
{
}

bool cPacketQueueDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cPacketQueue *>(obj)!=NULL;
}

const char *cPacketQueueDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cPacketQueueDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int cPacketQueueDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cPacketQueueDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "bitLength",
        "byteLength",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int cPacketQueueDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitLength")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "byteLength")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cPacketQueueDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int64",
        "int64",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *cPacketQueueDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Total size of messages in the queue";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Total size of messages in the queue, in bytes";
            return NULL;
        default: return NULL;
    }
}

int cPacketQueueDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cPacketQueue *pp = (cPacketQueue *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPacketQueueDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cPacketQueue *pp = (cPacketQueue *)object; (void)pp;
    switch (field) {
        case 0: return int642string(pp->getBitLength());
        case 1: return int642string(pp->getByteLength());
        default: return "";
    }
}

bool cPacketQueueDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cPacketQueue *pp = (cPacketQueue *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPacketQueueDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *cPacketQueueDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cPacketQueue *pp = (cPacketQueue *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cHasherDescriptor : public cClassDescriptor
{
  public:
    cHasherDescriptor();
    virtual ~cHasherDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cHasherDescriptor);

cHasherDescriptor::cHasherDescriptor() : cClassDescriptor("cHasher", "")
{
}

cHasherDescriptor::~cHasherDescriptor()
{
}

bool cHasherDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cHasher *>(obj)!=NULL;
}

const char *cHasherDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cHasherDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int cHasherDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cHasherDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "hash",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int cHasherDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hash")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cHasherDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *cHasherDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "str";
            if (!strcmp(propertyname,"hint")) return "The current hash value";
            return NULL;
        default: return NULL;
    }
}

int cHasherDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cHasher *pp = (cHasher *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cHasherDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cHasher *pp = (cHasher *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        default: return "";
    }
}

bool cHasherDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cHasher *pp = (cHasher *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cHasherDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *cHasherDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cHasher *pp = (cHasher *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cSimulationDescriptor : public cClassDescriptor
{
  public:
    cSimulationDescriptor();
    virtual ~cSimulationDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cSimulationDescriptor);

cSimulationDescriptor::cSimulationDescriptor() : cClassDescriptor("cSimulation", "cNoncopyableOwnedObject")
{
}

cSimulationDescriptor::~cSimulationDescriptor()
{
}

bool cSimulationDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cSimulation *>(obj)!=NULL;
}

const char *cSimulationDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "container";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cSimulationDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int cSimulationDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *cSimulationDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "simTime",
        "eventNumber",
        "messageQueue",
        "lastModuleId",
        "systemModule",
        "module",
        "hasher",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int cSimulationDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "simTime")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eventNumber")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageQueue")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastModuleId")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "systemModule")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "module")==0) return base+5;
    if (fieldName[0]=='h' && strcmp(fieldName, "hasher")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cSimulationDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "int64",
        "cMessageHeap",
        "int",
        "cModule",
        "cModule",
        "cHasher",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *cSimulationDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "The current simulation time in seconds";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "The current event number -- counts from 0 up";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Self-messages scheduled, and messages in transit";
            if (!strcmp(propertyname,"label")) return "futureEvents";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"group")) return "modules";
            if (!strcmp(propertyname,"hint")) return "The largest module ID issued so far";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"group")) return "modules";
            if (!strcmp(propertyname,"hint")) return "The top-level module";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"group")) return "modules";
            if (!strcmp(propertyname,"hint")) return "List of modules, indexed with module ID";
            if (!strcmp(propertyname,"label")) return "modules";
            if (!strcmp(propertyname,"sizeGetter")) return "getLastModuleId";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"hint")) return "Used for fingerprint calculation";
            return NULL;
        default: return NULL;
    }
}

int cSimulationDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cSimulation *pp = (cSimulation *)object; (void)pp;
    switch (field) {
        case 5: return pp->getLastModuleId();
        default: return 0;
    }
}

std::string cSimulationDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cSimulation *pp = (cSimulation *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getSimTime());
        case 1: return int642string(pp->getEventNumber());
        case 2: {std::stringstream out; out << pp->getMessageQueue(); return out.str();}
        case 3: return long2string(pp->getLastModuleId());
        case 4: {std::stringstream out; out << pp->getSystemModule(); return out.str();}
        case 5: {std::stringstream out; out << pp->getModule(i); return out.str();}
        case 6: {std::stringstream out; out << pp->getHasher(); return out.str();}
        default: return "";
    }
}

bool cSimulationDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cSimulation *pp = (cSimulation *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cSimulationDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        "cMessageHeap",
        NULL,
        "cModule",
        "cModule",
        "cHasher",
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *cSimulationDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cSimulation *pp = (cSimulation *)object; (void)pp;
    switch (field) {
        case 2: return (void *)static_cast<cObject *>(&pp->getMessageQueue()); break;
        case 4: return (void *)static_cast<cObject *>(pp->getSystemModule()); break;
        case 5: return (void *)static_cast<cObject *>(pp->getModule(i)); break;
        case 6: return (void *)(pp->getHasher()); break;
        default: return NULL;
    }
}

class cSchedulerDescriptor : public cClassDescriptor
{
  public:
    cSchedulerDescriptor();
    virtual ~cSchedulerDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cSchedulerDescriptor);

cSchedulerDescriptor::cSchedulerDescriptor() : cClassDescriptor("cScheduler", "cObject")
{
}

cSchedulerDescriptor::~cSchedulerDescriptor()
{
}

bool cSchedulerDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cScheduler *>(obj)!=NULL;
}

const char *cSchedulerDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cSchedulerDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cSchedulerDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cSchedulerDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cSchedulerDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cSchedulerDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cSchedulerDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cSchedulerDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cScheduler *pp = (cScheduler *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cSchedulerDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cScheduler *pp = (cScheduler *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cSchedulerDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cScheduler *pp = (cScheduler *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cSchedulerDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cSchedulerDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cScheduler *pp = (cScheduler *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cSequentialSchedulerDescriptor : public cClassDescriptor
{
  public:
    cSequentialSchedulerDescriptor();
    virtual ~cSequentialSchedulerDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cSequentialSchedulerDescriptor);

cSequentialSchedulerDescriptor::cSequentialSchedulerDescriptor() : cClassDescriptor("cSequentialScheduler", "cScheduler")
{
}

cSequentialSchedulerDescriptor::~cSequentialSchedulerDescriptor()
{
}

bool cSequentialSchedulerDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cSequentialScheduler *>(obj)!=NULL;
}

const char *cSequentialSchedulerDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cSequentialSchedulerDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cSequentialSchedulerDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cSequentialSchedulerDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cSequentialSchedulerDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cSequentialSchedulerDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cSequentialSchedulerDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cSequentialSchedulerDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cSequentialScheduler *pp = (cSequentialScheduler *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cSequentialSchedulerDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cSequentialScheduler *pp = (cSequentialScheduler *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cSequentialSchedulerDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cSequentialScheduler *pp = (cSequentialScheduler *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cSequentialSchedulerDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cSequentialSchedulerDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cSequentialScheduler *pp = (cSequentialScheduler *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cRealTimeSchedulerDescriptor : public cClassDescriptor
{
  public:
    cRealTimeSchedulerDescriptor();
    virtual ~cRealTimeSchedulerDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cRealTimeSchedulerDescriptor);

cRealTimeSchedulerDescriptor::cRealTimeSchedulerDescriptor() : cClassDescriptor("cRealTimeScheduler", "cScheduler")
{
}

cRealTimeSchedulerDescriptor::~cRealTimeSchedulerDescriptor()
{
}

bool cRealTimeSchedulerDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cRealTimeScheduler *>(obj)!=NULL;
}

const char *cRealTimeSchedulerDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cRealTimeSchedulerDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int cRealTimeSchedulerDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *cRealTimeSchedulerDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int cRealTimeSchedulerDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cRealTimeSchedulerDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *cRealTimeSchedulerDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int cRealTimeSchedulerDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cRealTimeScheduler *pp = (cRealTimeScheduler *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cRealTimeSchedulerDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cRealTimeScheduler *pp = (cRealTimeScheduler *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cRealTimeSchedulerDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cRealTimeScheduler *pp = (cRealTimeScheduler *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cRealTimeSchedulerDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *cRealTimeSchedulerDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cRealTimeScheduler *pp = (cRealTimeScheduler *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cTopology_NodeDescriptor : public cClassDescriptor
{
  public:
    cTopology_NodeDescriptor();
    virtual ~cTopology_NodeDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cTopology_NodeDescriptor);

cTopology_NodeDescriptor::cTopology_NodeDescriptor() : cClassDescriptor("cTopology_Node", "")
{
}

cTopology_NodeDescriptor::~cTopology_NodeDescriptor()
{
}

bool cTopology_NodeDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cTopology_Node *>(obj)!=NULL;
}

const char *cTopology_NodeDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cTopology_NodeDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int cTopology_NodeDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER,
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *cTopology_NodeDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "moduleId",
        "module",
        "weight",
        "enabled",
        "inLink",
        "outLink",
        "distanceToTarget",
        "path",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int cTopology_NodeDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "moduleId")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "module")==0) return base+1;
    if (fieldName[0]=='w' && strcmp(fieldName, "weight")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "enabled")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "inLink")==0) return base+4;
    if (fieldName[0]=='o' && strcmp(fieldName, "outLink")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "distanceToTarget")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "path")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cTopology_NodeDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "cModule",
        "double",
        "bool",
        "cTopology_LinkIn",
        "cTopology_LinkIn",
        "double",
        "cTopology_LinkOut",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *cTopology_NodeDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "ID of the module this node corresponds to";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "The module this node corresponds to";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Node weight -- affects graph algorithms such as shortest path";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"getter")) return "isEnabled";
            if (!strcmp(propertyname,"hint")) return "Node state -- affects graph algorithms such as shortest path";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"getter")) return "getLinkIn";
            if (!strcmp(propertyname,"hint")) return "Incoming links of this graph node";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumInLinks";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"getter")) return "getLinkOut";
            if (!strcmp(propertyname,"hint")) return "Outgoing links of this graph node";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumOutLinks";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"group")) return "shortest path";
            if (!strcmp(propertyname,"hint")) return "After running a shortest path algorithm: distance to the target node";
            return NULL;
        case 7:
            if (!strcmp(propertyname,"group")) return "shortest path";
            if (!strcmp(propertyname,"hint")) return "The next link of the shortest path or paths towards the target node";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumPaths";
            return NULL;
        default: return NULL;
    }
}

int cTopology_NodeDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_Node *pp = (cTopology_Node *)object; (void)pp;
    switch (field) {
        case 4: return pp->getNumInLinks();
        case 5: return pp->getNumOutLinks();
        case 7: return pp->getNumPaths();
        default: return 0;
    }
}

std::string cTopology_NodeDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_Node *pp = (cTopology_Node *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getModuleId());
        case 1: {std::stringstream out; out << pp->getModule(); return out.str();}
        case 2: return double2string(pp->getWeight());
        case 3: return bool2string(pp->isEnabled());
        case 4: {std::stringstream out; out << pp->getLinkIn(i); return out.str();}
        case 5: {std::stringstream out; out << pp->getLinkOut(i); return out.str();}
        case 6: return double2string(pp->getDistanceToTarget());
        case 7: {std::stringstream out; out << pp->getPath(i); return out.str();}
        default: return "";
    }
}

bool cTopology_NodeDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_Node *pp = (cTopology_Node *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopology_NodeDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "cModule",
        NULL,
        NULL,
        "cTopology_LinkIn",
        "cTopology_LinkIn",
        NULL,
        "cTopology_LinkOut",
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *cTopology_NodeDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_Node *pp = (cTopology_Node *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<cObject *>(pp->getModule()); break;
        case 4: return (void *)(pp->getLinkIn(i)); break;
        case 5: return (void *)(pp->getLinkOut(i)); break;
        case 7: return (void *)(pp->getPath(i)); break;
        default: return NULL;
    }
}

class cTopology_LinkDescriptor : public cClassDescriptor
{
  public:
    cTopology_LinkDescriptor();
    virtual ~cTopology_LinkDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cTopology_LinkDescriptor);

cTopology_LinkDescriptor::cTopology_LinkDescriptor() : cClassDescriptor("cTopology_Link", "")
{
}

cTopology_LinkDescriptor::~cTopology_LinkDescriptor()
{
}

bool cTopology_LinkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cTopology_Link *>(obj)!=NULL;
}

const char *cTopology_LinkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cTopology_LinkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int cTopology_LinkDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cTopology_LinkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "weight",
        "enabled",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int cTopology_LinkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='w' && strcmp(fieldName, "weight")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "enabled")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cTopology_LinkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "bool",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *cTopology_LinkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Link weight -- affects graph algorithms such as shortest path";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"getter")) return "isEnabled";
            if (!strcmp(propertyname,"hint")) return "Link state -- affects graph algorithms such as shortest path";
            return NULL;
        default: return NULL;
    }
}

int cTopology_LinkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_Link *pp = (cTopology_Link *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTopology_LinkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_Link *pp = (cTopology_Link *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getWeight());
        case 1: return bool2string(pp->isEnabled());
        default: return "";
    }
}

bool cTopology_LinkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_Link *pp = (cTopology_Link *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopology_LinkDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *cTopology_LinkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_Link *pp = (cTopology_Link *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

class cTopology_LinkInDescriptor : public cClassDescriptor
{
  public:
    cTopology_LinkInDescriptor();
    virtual ~cTopology_LinkInDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cTopology_LinkInDescriptor);

cTopology_LinkInDescriptor::cTopology_LinkInDescriptor() : cClassDescriptor("cTopology_LinkIn", "cTopology_Link")
{
}

cTopology_LinkInDescriptor::~cTopology_LinkInDescriptor()
{
}

bool cTopology_LinkInDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cTopology_LinkIn *>(obj)!=NULL;
}

const char *cTopology_LinkInDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cTopology_LinkInDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int cTopology_LinkInDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cTopology_LinkInDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "remoteNode",
        "remoteGate",
        "localGate",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int cTopology_LinkInDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteNode")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteGate")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "localGate")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cTopology_LinkInDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "cTopology_Node",
        "cGate",
        "cGate",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *cTopology_LinkInDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "The node at the remote end of this connection";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "The gate at the remote end of this connection";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "The gate at the local end of this connection";
            return NULL;
        default: return NULL;
    }
}

int cTopology_LinkInDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_LinkIn *pp = (cTopology_LinkIn *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTopology_LinkInDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_LinkIn *pp = (cTopology_LinkIn *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteNode(); return out.str();}
        case 1: {std::stringstream out; out << pp->getRemoteGate(); return out.str();}
        case 2: {std::stringstream out; out << pp->getLocalGate(); return out.str();}
        default: return "";
    }
}

bool cTopology_LinkInDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_LinkIn *pp = (cTopology_LinkIn *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopology_LinkInDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "cTopology_Node",
        "cGate",
        "cGate",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *cTopology_LinkInDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_LinkIn *pp = (cTopology_LinkIn *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(pp->getRemoteNode()); break;
        case 1: return (void *)static_cast<cObject *>(pp->getRemoteGate()); break;
        case 2: return (void *)static_cast<cObject *>(pp->getLocalGate()); break;
        default: return NULL;
    }
}

class cTopology_LinkOutDescriptor : public cClassDescriptor
{
  public:
    cTopology_LinkOutDescriptor();
    virtual ~cTopology_LinkOutDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cTopology_LinkOutDescriptor);

cTopology_LinkOutDescriptor::cTopology_LinkOutDescriptor() : cClassDescriptor("cTopology_LinkOut", "cTopology_Link")
{
}

cTopology_LinkOutDescriptor::~cTopology_LinkOutDescriptor()
{
}

bool cTopology_LinkOutDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cTopology_LinkOut *>(obj)!=NULL;
}

const char *cTopology_LinkOutDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cTopology_LinkOutDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int cTopology_LinkOutDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cTopology_LinkOutDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "remoteNode",
        "remoteGate",
        "localGate",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int cTopology_LinkOutDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteNode")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteGate")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "localGate")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cTopology_LinkOutDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "cTopology_Node",
        "cGate",
        "cGate",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *cTopology_LinkOutDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "The node at the remote end of this connection";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "The gate at the remote end of this connection";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "The gate at the local end of this connection";
            return NULL;
        default: return NULL;
    }
}

int cTopology_LinkOutDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_LinkOut *pp = (cTopology_LinkOut *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTopology_LinkOutDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_LinkOut *pp = (cTopology_LinkOut *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteNode(); return out.str();}
        case 1: {std::stringstream out; out << pp->getRemoteGate(); return out.str();}
        case 2: {std::stringstream out; out << pp->getLocalGate(); return out.str();}
        default: return "";
    }
}

bool cTopology_LinkOutDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_LinkOut *pp = (cTopology_LinkOut *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopology_LinkOutDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "cTopology_Node",
        "cGate",
        "cGate",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *cTopology_LinkOutDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology_LinkOut *pp = (cTopology_LinkOut *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(pp->getRemoteNode()); break;
        case 1: return (void *)static_cast<cObject *>(pp->getRemoteGate()); break;
        case 2: return (void *)static_cast<cObject *>(pp->getLocalGate()); break;
        default: return NULL;
    }
}

class cTopologyDescriptor : public cClassDescriptor
{
  public:
    cTopologyDescriptor();
    virtual ~cTopologyDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cTopologyDescriptor);

cTopologyDescriptor::cTopologyDescriptor() : cClassDescriptor("cTopology", "cOwnedObject")
{
}

cTopologyDescriptor::~cTopologyDescriptor()
{
}

bool cTopologyDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cTopology *>(obj)!=NULL;
}

const char *cTopologyDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cTopologyDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int cTopologyDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cTopologyDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "numNodes",
        "node",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int cTopologyDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numNodes")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "node")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cTopologyDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "cTopology_Node",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *cTopologyDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Number of nodes in this topology object";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "List of nodes in this topology object";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumNodes";
            return NULL;
        default: return NULL;
    }
}

int cTopologyDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cTopology *pp = (cTopology *)object; (void)pp;
    switch (field) {
        case 1: return pp->getNumNodes();
        default: return 0;
    }
}

std::string cTopologyDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology *pp = (cTopology *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNumNodes());
        case 1: {std::stringstream out; out << pp->getNode(i); return out.str();}
        default: return "";
    }
}

bool cTopologyDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cTopology *pp = (cTopology *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopologyDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "cTopology_Node",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *cTopologyDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cTopology *pp = (cTopology *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(pp->getNode(i)); break;
        default: return NULL;
    }
}

class cXMLElementDescriptor : public cClassDescriptor
{
  public:
    cXMLElementDescriptor();
    virtual ~cXMLElementDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(cXMLElementDescriptor);

cXMLElementDescriptor::cXMLElementDescriptor() : cClassDescriptor("cXMLElement", "cObject")
{
}

cXMLElementDescriptor::~cXMLElementDescriptor()
{
}

bool cXMLElementDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cXMLElement *>(obj)!=NULL;
}

const char *cXMLElementDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cXMLElementDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int cXMLElementDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *cXMLElementDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "tagName",
        "nodeValue",
        "sourceLocation",
        "hasAttributes",
        "hasChildren",
        "detailedInfo",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int cXMLElementDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tagName")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeValue")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceLocation")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hasAttributes")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hasChildren")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "detailedInfo")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cXMLElementDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "bool",
        "bool",
        "string",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *cXMLElementDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "XML element tag";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Contents of text node inside this XML element";
            return NULL;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Location this XML element was parsed from";
            return NULL;
        case 3:
            if (!strcmp(propertyname,"getter")) return "hasAttributes";
            if (!strcmp(propertyname,"hint")) return "Whether this XML element has attributes";
            return NULL;
        case 4:
            if (!strcmp(propertyname,"getter")) return "hasChildren";
            if (!strcmp(propertyname,"hint")) return "Whether this XML element has child elements";
            return NULL;
        case 5:
            if (!strcmp(propertyname,"getter")) return "detailedInfo";
            if (!strcmp(propertyname,"label")) return "contents";
            return NULL;
        default: return NULL;
    }
}

int cXMLElementDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cXMLElement *pp = (cXMLElement *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cXMLElementDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cXMLElement *pp = (cXMLElement *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getTagName());
        case 1: return oppstring2string(pp->getNodeValue());
        case 2: return oppstring2string(pp->getSourceLocation());
        case 3: return bool2string(pp->hasAttributes());
        case 4: return bool2string(pp->hasChildren());
        case 5: return oppstring2string(pp->detailedInfo());
        default: return "";
    }
}

bool cXMLElementDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cXMLElement *pp = (cXMLElement *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cXMLElementDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *cXMLElementDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cXMLElement *pp = (cXMLElement *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


