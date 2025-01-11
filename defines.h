/****BIT******/
/***(ARGUMENTED MACROS)*****/

#define WRITENIBBLE(WORD,NIBBLESTARTBIT,NIBBLE) \
WORD=((WORD&~(15<<NIBBLESTARTBIT))\
|(NIBBLE<<NIBBLESTARTBIT))
#define SETBIT(WORD,BIT) (WORD|=1<<BIT)
#define SSETBIT(WORD,BIT) (WORD=1<<BIT)
#define CLRBIT(WORD,BIT) (WORD&=~(1<<BIT))
#define SCLRBIT(WORD,BIT) (WORD=1<<BIT)
#define CPLBIT(WORD,BIT) (WORD^=1<<BIT)
#define READBIT(WORD,BIT) ((WORD>>BIT)&1)
#define READNIBBLE(WORD,NIBBLESTARTBIT)\
((WORD>>NIBBLESTARTBIT)&15)
#define WRITEBIT(WORD,BIT,BITLEVEL)\
WORD=((WORD&~(1<<BIT))|(BITLEVEL<<BIT))
#define READWRITEBIT(DWORD,DBIT,SWORD,SBIT)\
DWORD=((DWORD&~(1<<DBIT))|((SWORD>>SBIT)&1)<<DBIT);

/*******BYTE*******/

#define WRITEBYTE(WORD,BYTESTARTBIT,BYTE) (WORD=((WORD&~(255<<BYTESTARTBIT))|(BYTE<<BYTESTARTBIT)))
#define READBYTE(WORD,BYTESTARTBIT)\
((WORD>>BYTESTARTBIT)&255)
