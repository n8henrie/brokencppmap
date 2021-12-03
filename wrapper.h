typedef void* CConfiguration;

#ifdef __cplusplus
extern "C" {
#endif

struct config;
typedef struct config config_t;

config_t *newConfig();
void delConfig(config_t *c);
void setInherited(config_t *c);
void printInherited(config_t *c);

#ifdef __cplusplus
}
#endif
