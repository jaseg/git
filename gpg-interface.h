#ifndef GPG_INTERFACE_H
#define GPG_INTERFACE_H

struct signature {
	char *gpg_output;
	char check_result; /* 0 (not checked), N (checked but no further result), U (untrusted, good), G (good) or B (bad) */
	char *signer;
};

extern int sign_buffer(struct strbuf *buffer, struct strbuf *signature, const char *signing_key);
extern int verify_signed_buffer(const char *payload, size_t payload_size, const char *signature, size_t signature_size, struct strbuf *gpg_output);
extern int git_gpg_config(const char *, const char *, void *);
extern void set_signing_key(const char *);
extern const char *get_signing_key(void);

#endif
