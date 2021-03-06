/* Hash score: 156 */
static int keywordCode(const char *z, int n){
  static const char zText[526] =
    "ABORTABLEFTEMPORARYADDATABASELECTHENDEFAULTRANSACTIONATURALTER"
    "AISEACHECKEYAFTEREFERENCESCAPELSEXCEPTRIGGEREGEXPLAINITIALLYANALYZE"
    "XCLUSIVEXISTSTATEMENTANDEFERRABLEATTACHAVINGLOBEFOREIGNOREINDEX"
    "AUTOINCREMENTBEGINNERENAMEBETWEENOTNULLIKEBYCASCADEFERREDELETE"
    "CASECASTCOLLATECOLUMNCOMMITCONFLICTCONSTRAINTERSECTCREATECROSS"
    "CURRENT_DATECURRENT_TIMESTAMPRAGMATCHDESCDETACHDISTINCTDROPRIMARY"
    "FAILIMITFROMFULLGROUPDATEIMMEDIATEINSERTINSTEADINTOFFSETISNULL"
    "JOINORDEREPLACEOUTERESTRICTRIGHTROLLBACKROWHENUNIONUNIQUEUSING"
    "VACUUMVALUESVIEWHERE";
  static const unsigned char aHash[127] = {
      91,  81, 104,  90,   0,   4,   0,   0, 111,   0,  77,   0,   0,
      94,  44,   0,  92,   0, 103, 106,  96,   0,   0,  10,   0,   0,
     110,   0, 107, 102,   0,  28,  48,   0,  41,   0,   0,  65,  71,
       0,  63,  19,   0,   0,  36,  83,   0, 105,  74,   0,   0,  33,
       0,  61,  37,   0,   8,   0, 112,  38,  12,   0,  78,  40,  25,
      66,   0,   0,  31,  82,  53,  30,  50,  20,  88,   0,  34,   0,
      75,  26,   0,  72,   0,   0,   0,  64,  47,  67,  22,  87,  29,
      69,  86,   0,   1,   0,   9, 100,  58,  18,   0, 109,  76,  98,
      54,   6,  85,   0,   0,  49,  93,   0, 101,   0,  70,   0,   0,
      15,   0, 113,  51,  56,   0,   2,  55,   0, 108,
  };
  static const unsigned char aNext[113] = {
       0,   0,   0,   0,   0,   3,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,  17,   0,   0,   0,   0,
       0,  11,   0,   0,   0,   0,   5,  13,   0,   7,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,  43,   0,   0,   0,   0,   0,
       0,   0,  16,   0,  23,  52,   0,   0,   0,   0,  45,   0,  59,
       0,   0,   0,   0,   0,   0,   0,   0,  73,  42,   0,   0,  24,
      60,  21,   0,  80,  32,  68,   0,   0,  84,  46,   0,   0,   0,
       0,   0,   0,   0,  39,  95,  97,   0,   0,  99,   0,  14,  27,
      79,   0,  57,  89,   0,  35,   0,  62,   0,
  };
  static const unsigned char aLen[113] = {
       5,   5,   4,   4,   9,   2,   3,   8,   2,   6,   4,   3,   7,
      11,   2,   7,   5,   5,   4,   5,   3,   5,  10,   6,   4,   6,
       7,   6,   7,   9,   3,   7,   9,   6,   9,   3,  10,   6,   6,
       4,   6,   3,   7,   6,   7,   5,  13,   2,   2,   5,   5,   6,
       7,   3,   7,   4,   4,   2,   7,   3,   8,   6,   4,   4,   7,
       6,   6,   8,  10,   9,   6,   5,  12,  12,  17,   6,   5,   4,
       6,   8,   2,   4,   7,   4,   5,   4,   4,   5,   6,   9,   6,
       7,   4,   2,   6,   3,   6,   4,   5,   7,   5,   8,   5,   8,
       3,   4,   5,   6,   5,   6,   6,   4,   5,
  };
  static const unsigned short int aOffset[113] = {
       0,   4,   7,  10,  10,  14,  19,  21,  26,  27,  32,  34,  36,
      42,  51,  52,  57,  61,  65,  67,  71,  74,  78,  86,  91,  94,
      99, 105, 108, 113, 118, 122, 128, 136, 141, 150, 152, 162, 167,
     172, 175, 177, 177, 181, 185, 187, 192, 194, 196, 205, 208, 212,
     218, 224, 224, 227, 230, 234, 236, 237, 241, 248, 254, 258, 262,
     269, 275, 281, 289, 296, 305, 311, 316, 328, 328, 344, 348, 353,
     357, 363, 364, 371, 374, 381, 384, 389, 393, 397, 400, 406, 415,
     421, 428, 431, 431, 434, 437, 443, 447, 451, 458, 462, 470, 475,
     483, 485, 489, 494, 500, 505, 511, 517, 520,
  };
  static const unsigned char aCode[113] = {
    TK_ABORT,      TK_TABLE,      TK_JOIN_KW,    TK_TEMP,       TK_TEMP,       
    TK_OR,         TK_ADD,        TK_DATABASE,   TK_AS,         TK_SELECT,     
    TK_THEN,       TK_END,        TK_DEFAULT,    TK_TRANSACTION,TK_ON,         
    TK_JOIN_KW,    TK_ALTER,      TK_RAISE,      TK_EACH,       TK_CHECK,      
    TK_KEY,        TK_AFTER,      TK_REFERENCES, TK_ESCAPE,     TK_ELSE,       
    TK_EXCEPT,     TK_TRIGGER,    TK_LIKE_KW,    TK_EXPLAIN,    TK_INITIALLY,  
    TK_ALL,        TK_ANALYZE,    TK_EXCLUSIVE,  TK_EXISTS,     TK_STATEMENT,  
    TK_AND,        TK_DEFERRABLE, TK_ATTACH,     TK_HAVING,     TK_LIKE_KW,    
    TK_BEFORE,     TK_FOR,        TK_FOREIGN,    TK_IGNORE,     TK_REINDEX,    
    TK_INDEX,      TK_AUTOINCR,   TK_TO,         TK_IN,         TK_BEGIN,      
    TK_JOIN_KW,    TK_RENAME,     TK_BETWEEN,    TK_NOT,        TK_NOTNULL,    
    TK_NULL,       TK_LIKE_KW,    TK_BY,         TK_CASCADE,    TK_ASC,        
    TK_DEFERRED,   TK_DELETE,     TK_CASE,       TK_CAST,       TK_COLLATE,    
    TK_COLUMNKW,   TK_COMMIT,     TK_CONFLICT,   TK_CONSTRAINT, TK_INTERSECT,  
    TK_CREATE,     TK_JOIN_KW,    TK_CTIME_KW,   TK_CTIME_KW,   TK_CTIME_KW,   
    TK_PRAGMA,     TK_MATCH,      TK_DESC,       TK_DETACH,     TK_DISTINCT,   
    TK_IS,         TK_DROP,       TK_PRIMARY,    TK_FAIL,       TK_LIMIT,      
    TK_FROM,       TK_JOIN_KW,    TK_GROUP,      TK_UPDATE,     TK_IMMEDIATE,  
    TK_INSERT,     TK_INSTEAD,    TK_INTO,       TK_OF,         TK_OFFSET,     
    TK_SET,        TK_ISNULL,     TK_JOIN,       TK_ORDER,      TK_REPLACE,    
    TK_JOIN_KW,    TK_RESTRICT,   TK_JOIN_KW,    TK_ROLLBACK,   TK_ROW,        
    TK_WHEN,       TK_UNION,      TK_UNIQUE,     TK_USING,      TK_VACUUM,     
    TK_VALUES,     TK_VIEW,       TK_WHERE,      
  };
  int h, i;
  if( n<2 ) return TK_ID;
  h = ((sqlite3UpperToLower[((unsigned char*)z)[0]]*4) ^
      (sqlite3UpperToLower[((unsigned char*)z)[n-1]]*3) ^
      n) % 127;
  for(i=((int)aHash[h])-1; i>=0; i=((int)aNext[i])-1){
    if( aLen[i]==n && sqlite3StrNICmp(&zText[aOffset[i]],z,n)==0 ){
      return aCode[i];
    }
  }
  return TK_ID;
}
int sqlite3KeywordCode(const char *z, int n){
  return keywordCode(z, n);
}
