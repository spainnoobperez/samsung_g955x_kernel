#ifndef _SECDP_LOGGER_H_
#define _SECDP_LOGGER_H_

#ifdef CONFIG_SEC_DISPLAYPORT_LOGGER

void dp_logger_set_max_count(int count);
void dp_logger_print(const char *fmt, ...);
void dp_print_hex_dump(void *buf, void *pref, size_t len);
int  init_dp_logger(void);

#define secdp_proc_info(fmt, ...) \
	do { \
		printk(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__); \
		dp_logger_print(fmt, ##__VA_ARGS__); \
	} while (0)

#define secdp_pr_info(fmt, ...) \
		printk(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__)

#ifdef pr_debug
#undef pr_debug
#define pr_debug	secdp_pr_info
#endif
#ifdef DEV_DBG
#undef DEV_DBG
#define DEV_DBG		secdp_pr_info
#endif

#ifdef pr_err
#undef pr_err
#define pr_err		secdp_proc_info
#endif
#ifdef DEV_ERR
#undef DEV_ERR
#define DEV_ERR		secdp_proc_info
#endif

#ifdef pr_info
#undef pr_info
#define pr_info		secdp_proc_info
#endif
#ifdef DEV_INFO
#undef DEV_INFO
#define DEV_INFO	secdp_proc_info
#endif

#else/* !CONFIG_SEC_DISPLAYPORT_LOGGER */

#define dp_logger_set_max_count(x)			do {} while (0)
#define dp_logger_print(fmt, ...)			do {} while (0)
#define dp_print_hex_dump(buf, pref, len)	do {} while (0)
#define init_dp_logger(void)				do {} while (0)

#ifdef pr_debug
#undef pr_debug
#define pr_debug	pr_info
#endif

#ifdef DEV_DBG
#undef DEV_DBG
#define DEV_DBG		pr_info
#endif

#endif

#endif/*_SECDP_LOGGER_H_*/
