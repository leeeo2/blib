
#ifndef _LHASH_H_
#define _LHASH_H_


#include <vector>
#include <iostream>

/*
 *  采用线性探测法实现哈希表
 *  参考：https://github.com/jwasham/practice-cpp/blob/master/hash_table/hash_table.cc
 */

namespace lx{

	class hashObject{
	public:
		hashObject(){}
		hashObject(std::string k, std::string v) :key(k), value(v){}
		~hashObject(){}

		void setKey(std::string k){ key = k;}

		void setValue(std::string v){ value = v;}

		std::string getKey(){ return key; }

		static const std::string getNullKey() { return "<null>"; }

		std::string getValue(){ return value; }

	private:
		std::string key;
		std::string value;
	};


	class lhash{
	public:
		lhash(std::size_t len);
		~lhash();
		/*   add a key-value to hash,if key exists ,update its value   */
		void add(std::string key, std::string value);

		/*   if key exists in hash   */
		bool exists(std::string key);

		/*   get value from hash by key   */
		std::string get(std::string key);

		/*   remove key-value from hash by key   */
		void remove(std::string key);
	private:
		/*   hash function   */
		std::size_t hash(std::string key);

	private:
		/*   data storage   */
		hashObject *data;
		std::size_t len;
	};
}




#endif