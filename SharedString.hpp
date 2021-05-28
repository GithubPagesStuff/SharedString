#include "blake2.h"
#include "base64.h"
// set it to your namespace when you want to.
class SharedString {
public:
	char *value;
	unsigned char *hash;
	static SharedString* all[];
	static int allAmount;
	SharedString(char* val){
		allAmount++;
		value = val;
		all[allAmount]=this;
		hash = this->serialize();
	};
	
	unsigned char* serialize() {
		char currentvalue[strlen(this->value)+1];
		strcpy(currentvalue, this->value);
		unsigned char *res = (unsigned char*)malloc(BLAKE2B_OUTBYTES*sizeof(unsigned char));
		blake2b(res, currentvalue, NULL, BLAKE2B_OUTBYTES, strlen(this->value), 0);
		unsigned char *res2 = (unsigned char*)malloc(Base64encode_len(BLAKE2B_OUTBYTES*sizeof(unsigned char)));
		Base64encode((char*)res2, (char*)res, BLAKE2B_OUTBYTES);
		free(res);
#ifdef __OBJC__
		NSLog([[NSData dataWithBytes:res length:BLAKE2B_OUTBYTES] base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength]);
#endif
		return const_cast<unsigned char*>(res2);
		;
	}
	static SharedString* deserialize(unsigned char* e) {
		for (int i=0; i<=allAmount; i++) {//strcmp((char*)all[i]->hash, (char*)e)
			//printf("%i", strcmp((char*)all[i]->hash, (char*)e));
			if (strcmp((char*)all[i]->hash, (char*)e) == 0) {
				return all[i];
			}
		}
		return nullptr;
	}
};
#include "blake2.h"
#include "base64.h"
// set it to your namespace when you want to.
class SharedString {
public:
	char *value;
	unsigned char *hash;
	static SharedString* all[];
	static int allAmount;
	SharedString(char* val){
		allAmount++;
		value = val;
		all[allAmount]=this;
		hash = this->serialize();
	};
	
	unsigned char* serialize() {
		char currentvalue[strlen(this->value)+1];
		strcpy(currentvalue, this->value);
		unsigned char *res = (unsigned char*)malloc(BLAKE2B_OUTBYTES*sizeof(unsigned char));
		blake2b(res, currentvalue, NULL, BLAKE2B_OUTBYTES, strlen(this->value), 0);
		unsigned char *res2 = (unsigned char*)malloc(Base64encode_len(BLAKE2B_OUTBYTES*sizeof(unsigned char)));
		Base64encode((char*)res2, (char*)res, BLAKE2B_OUTBYTES);
		free(res);
#ifdef __OBJC__
		NSLog([[NSData dataWithBytes:res length:BLAKE2B_OUTBYTES] base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength]);
#endif
		return const_cast<unsigned char*>(res2);
		;
	}
	static SharedString* deserialize(unsigned char* e) {
		for (int i=0; i<=allAmount; i++) {//strcmp((char*)all[i]->hash, (char*)e)
			//printf("%i", strcmp((char*)all[i]->hash, (char*)e));
			if (strcmp((char*)all[i]->hash, (char*)e) == 0) {
				return all[i];
			}
		}
		return nullptr;
	}
};
