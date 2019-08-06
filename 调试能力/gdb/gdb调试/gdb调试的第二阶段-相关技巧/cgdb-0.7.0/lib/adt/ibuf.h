#ifndef __IBUF_H__
#define __IBUF_H__

/* A simple interface to an infinite string */
struct ibuf;

/* ibuf_init: Returns a new infinite string.  */
struct ibuf *ibuf_init(void);

/* ibuf_free: free a string */
void ibuf_free(struct ibuf *s);

/* clears the string s */
void ibuf_clear(struct ibuf *s);

/* ibuf_addchar: Adds a char to the infinite buffer
 *  s - the infinite string to modify
 *  c - the char to add
 */
void ibuf_addchar(struct ibuf *s, char c);

/**
 * Adds a char to the infinite buffer.
 *
 * @param s
 * the infinite string to modify
 *
 * @param d
 * the string to add
 *
 * @return
 * The number of characters added to the buffer (the length of d)
 */
int ibuf_add(struct ibuf *s, const char *d);

/* ibuf_delchar: Delete the last char put in */
void ibuf_delchar(struct ibuf *s);

/* ibuf_get: returns the string 
 *  return  - the string returned is valid until ibuf_free is called 
 *  NOTE: This function adds a '\0' to the end of the string if it is not 
 *        the last char
 */
char *ibuf_get(struct ibuf *s);

/* ibuf_length: Returns the length of string s */
unsigned long ibuf_length(struct ibuf *s);

/*
 * This will return a valid string that is equal to s.
 *
 * Returns
 *    New string on success, NULL on error.
 */
struct ibuf *ibuf_dup(struct ibuf *s);

#endif /* HAVE_CONFIG_H */
