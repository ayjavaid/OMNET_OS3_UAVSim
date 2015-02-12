//
// Generated file, do not edit! Created by opp_msgc 4.4 from GPSPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "GPSPacket_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(GPSPacket);

GPSPacket::GPSPacket(const char *name, int kind) : ::cPacket(name,kind)
{
    this->sourcePort_var = 0;
    this->destinationPort_var = 0;
    this->longitude_var = 0;
    this->latitude_var = 0;
    this->altitude_var = 0;
    this->elevation_var = 0;
    distance_arraysize = 0;
    this->distance_var = 0;
}

GPSPacket::GPSPacket(const GPSPacket& other) : ::cPacket(other)
{
    distance_arraysize = 0;
    this->distance_var = 0;
    copy(other);
}

GPSPacket::~GPSPacket()
{
    delete [] distance_var;
}

GPSPacket& GPSPacket::operator=(const GPSPacket& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void GPSPacket::copy(const GPSPacket& other)
{
    this->sourcePort_var = other.sourcePort_var;
    this->destinationPort_var = other.destinationPort_var;
    this->longitude_var = other.longitude_var;
    this->latitude_var = other.latitude_var;
    this->altitude_var = other.altitude_var;
    this->elevation_var = other.elevation_var;
    delete [] this->distance_var;
    this->distance_var = (other.distance_arraysize==0) ? NULL : new double[other.distance_arraysize];
    distance_arraysize = other.distance_arraysize;
    for (unsigned int i=0; i<distance_arraysize; i++)
        this->distance_var[i] = other.distance_var[i];
}

void GPSPacket::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->sourcePort_var);
    doPacking(b,this->destinationPort_var);
    doPacking(b,this->longitude_var);
    doPacking(b,this->latitude_var);
    doPacking(b,this->altitude_var);
    doPacking(b,this->elevation_var);
    b->pack(distance_arraysize);
    doPacking(b,this->distance_var,distance_arraysize);
}

void GPSPacket::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->sourcePort_var);
    doUnpacking(b,this->destinationPort_var);
    doUnpacking(b,this->longitude_var);
    doUnpacking(b,this->latitude_var);
    doUnpacking(b,this->altitude_var);
    doUnpacking(b,this->elevation_var);
    delete [] this->distance_var;
    b->unpack(distance_arraysize);
    if (distance_arraysize==0) {
        this->distance_var = 0;
    } else {
        this->distance_var = new double[distance_arraysize];
        doUnpacking(b,this->distance_var,distance_arraysize);
    }
}

unsigned short GPSPacket::getSourcePort() const
{
    return sourcePort_var;
}

void GPSPacket::setSourcePort(unsigned short sourcePort)
{
    this->sourcePort_var = sourcePort;
}

unsigned short GPSPacket::getDestinationPort() const
{
    return destinationPort_var;
}

void GPSPacket::setDestinationPort(unsigned short destinationPort)
{
    this->destinationPort_var = destinationPort;
}

double GPSPacket::getLongitude() const
{
    return longitude_var;
}

void GPSPacket::setLongitude(double longitude)
{
    this->longitude_var = longitude;
}

double GPSPacket::getLatitude() const
{
    return latitude_var;
}

void GPSPacket::setLatitude(double latitude)
{
    this->latitude_var = latitude;
}

double GPSPacket::getAltitude() const
{
    return altitude_var;
}

void GPSPacket::setAltitude(double altitude)
{
    this->altitude_var = altitude;
}

double GPSPacket::getElevation() const
{
    return elevation_var;
}

void GPSPacket::setElevation(double elevation)
{
    this->elevation_var = elevation;
}

void GPSPacket::setDistanceArraySize(unsigned int size)
{
    double *distance_var2 = (size==0) ? NULL : new double[size];
    unsigned int sz = distance_arraysize < size ? distance_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        distance_var2[i] = this->distance_var[i];
    for (unsigned int i=sz; i<size; i++)
        distance_var2[i] = 0;
    distance_arraysize = size;
    delete [] this->distance_var;
    this->distance_var = distance_var2;
}

unsigned int GPSPacket::getDistanceArraySize() const
{
    return distance_arraysize;
}

double GPSPacket::getDistance(unsigned int k) const
{
    if (k>=distance_arraysize) throw cRuntimeError("Array of size %d indexed by %d", distance_arraysize, k);
    return distance_var[k];
}

void GPSPacket::setDistance(unsigned int k, double distance)
{
    if (k>=distance_arraysize) throw cRuntimeError("Array of size %d indexed by %d", distance_arraysize, k);
    this->distance_var[k] = distance;
}

class GPSPacketDescriptor : public cClassDescriptor
{
  public:
    GPSPacketDescriptor();
    virtual ~GPSPacketDescriptor();

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

Register_ClassDescriptor(GPSPacketDescriptor);

GPSPacketDescriptor::GPSPacketDescriptor() : cClassDescriptor("GPSPacket", "cPacket")
{
}

GPSPacketDescriptor::~GPSPacketDescriptor()
{
}

bool GPSPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<GPSPacket *>(obj)!=NULL;
}

const char *GPSPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int GPSPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int GPSPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *GPSPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sourcePort",
        "destinationPort",
        "longitude",
        "latitude",
        "altitude",
        "elevation",
        "distance",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int GPSPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourcePort")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationPort")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "longitude")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "latitude")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "altitude")==0) return base+4;
    if (fieldName[0]=='e' && strcmp(fieldName, "elevation")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "distance")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *GPSPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned short",
        "double",
        "double",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *GPSPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int GPSPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    GPSPacket *pp = (GPSPacket *)object; (void)pp;
    switch (field) {
        case 6: return pp->getDistanceArraySize();
        default: return 0;
    }
}

std::string GPSPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    GPSPacket *pp = (GPSPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSourcePort());
        case 1: return ulong2string(pp->getDestinationPort());
        case 2: return double2string(pp->getLongitude());
        case 3: return double2string(pp->getLatitude());
        case 4: return double2string(pp->getAltitude());
        case 5: return double2string(pp->getElevation());
        case 6: return double2string(pp->getDistance(i));
        default: return "";
    }
}

bool GPSPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    GPSPacket *pp = (GPSPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourcePort(string2ulong(value)); return true;
        case 1: pp->setDestinationPort(string2ulong(value)); return true;
        case 2: pp->setLongitude(string2double(value)); return true;
        case 3: pp->setLatitude(string2double(value)); return true;
        case 4: pp->setAltitude(string2double(value)); return true;
        case 5: pp->setElevation(string2double(value)); return true;
        case 6: pp->setDistance(i,string2double(value)); return true;
        default: return false;
    }
}

const char *GPSPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *GPSPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    GPSPacket *pp = (GPSPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


