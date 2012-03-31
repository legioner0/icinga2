#ifndef I2_CONFIGHIVE_H
#define I2_CONFIGHIVE_H

#include <map>

namespace icinga
{

using std::map;

struct ConfigHiveEventArgs : public EventArgs
{
	typedef shared_ptr<ConfigHiveEventArgs> RefType;
	typedef weak_ptr<ConfigHiveEventArgs> WeakRefType;

	ConfigObject::RefType ConfigObject;
	string Property;
	string OldValue;
};

class ConfigHive : public Object
{
public:
	typedef shared_ptr<ConfigHive> RefType;
	typedef weak_ptr<ConfigHive> WeakRefType;

	typedef map< string, map<string, ConfigObject::RefType> >::iterator TypeIterator;
	typedef map<string, ConfigObject::RefType>::iterator ObjectIterator;
	map< string, map<string, ConfigObject::RefType> > Objects;

	void AddObject(ConfigObject::RefType object);
	void RemoveObject(ConfigObject::RefType object);
	ConfigObject::RefType GetObject(const string& type, const string& name = string());

	event<ConfigHiveEventArgs::RefType> OnObjectCreated;
	event<ConfigHiveEventArgs::RefType> OnObjectRemoved;
	event<ConfigHiveEventArgs::RefType> OnPropertyChanged;
};

}

#endif /* I2_CONFIGHIVE_H */
