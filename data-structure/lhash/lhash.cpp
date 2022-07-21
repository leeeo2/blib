
#include "lhash.h"




lx::lhash::lhash(std::size_t l) :len(l){
	try{
		data = new hashObject[len];
	}
	catch (std::bad_alloc &e){
		std::cout << "bad_alloc" << e.what() << std::endl;
	}
	for (std::size_t i = 0; i < len; i++) {
		data[i].setKey(hashObject::getNullKey());
	}
}


lx::lhash::~lhash(){
	if (data){
		delete[]data;
	}
}


void lx::lhash::add(std::string key, std::string value){
    std::size_t index = hash(key);
	std::size_t i = 0;
	while (i<len&&data[index].getKey != hashObject::getNullKey()) {
		index = (index + 1) % len;
	}


    if(i==len-1){
		data[index].setKey(key);
		data[index].setValue(value);
	}
	else {
		return;
	}

}


bool lx::lhash::exists(std::string key){
	std::size_t index = hash(key);
	if (data[index].getKey() != hashObject::getNullKey()) {
		return true;
	}
	return false;
}


std::string lx::lhash::get(std::string key) {
	std::size_t index = hash(key);
	return data[index].getValue();
}

void lx::lhash::remove(std::string key) {
	std::size_t index = hash(key);
	data[index].setKey(hashObject::getNullKey());
}



std::size_t lx::lhash::hash(std::string key){
	std::size_t ha = 0;
	for (auto c : key) {
		ha = ha * 131 + c;
	}
	return ha;
}