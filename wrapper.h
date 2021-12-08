#ifdef __cplusplus
extern "C" {
#endif

typedef struct Configuration Configuration;

Configuration *newConfig();
void delConfig(Configuration *c);
void setInherited(Configuration *c);
void printInherited(Configuration *c);
void setComposed(Configuration *c);
void printComposed(Configuration *c);

#ifdef __cplusplus
}
#endif
