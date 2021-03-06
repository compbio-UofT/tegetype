#ifndef globals_hpp_
#define globals_hpp_

#undef EXTERN
#undef STATIC
#ifdef MODULE_MAIN_
#define EXTERN_INIT(_type, _id, _init_val) extern _type _id; _type _id = _init_val
#define EXTERN(_type, _id) extern _type _id; _type _id
#else
#define EXTERN_INIT(_type, _id, _init_val) extern _type _id
#define EXTERN(_type, _id) extern _type _id
#endif

#define CONCAT(...) __VA_ARGS__

#include <map>
#include <string>

#include "DNASequence.hpp"
#include "Pairing.hpp"


namespace global {

  EXTERN_INIT(int const, min_read_len, 20);
  EXTERN_INIT(int, min_tail_len, 8);
  EXTERN(SQDict, refDict);
  EXTERN(SQDict, repDict);

  EXTERN(ReadGroupSet, rg_set);
  EXTERN_INIT(string, default_rg_name, "00");

  EXTERN(CONCAT(vector<pair<Contig*,int> >), repeatListAll);
  EXTERN(CONCAT(vector<pair<Contig*,int> >), repeatListSt[2]);
  EXTERN_INIT(bool, full_splitmap_log, false);

  EXTERN(int, verbosity);
  EXTERN_INIT(int, num_threads, 1);
};

#define LOG(level) if (level <= global::verbosity) clog


#endif
