#ifndef MemoryHeaderGuard
#define MemoryHeaderGuard

namespace Memory {
   bool compareMemory(const char*, const char*, const char*);
   long findPattern(long, long, const char*, const char*);
   long signatureScan(const char*, const char*);
   long vftableScan(const char*);
}

#endif
