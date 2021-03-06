#ifndef _SLRN_FEATURES_H
#define _SLRN_FEATURES_H
/* Note!!!
 * Lines beginning with '#' characters do NOT indicate that the line is
 * commented out.  C does NOT use '#' as a comment character.  In this file, 
 * '1' indicates that the feature will be turned on, and '0' indicates that
 * the feature will be turned off.
 */

/* If non-zero, a special message will be displayed when article is the last
 * one in a thread.
 */
#define SLRN_HAS_END_OF_THREAD	1

/* Unset this if you have inews support enabled and do not want to allow
 * users to set the inews command slrn invokes. */
#define SLRN_HAS_USER_INEWS	1

/* The sltcp interface is necessary for simultaneous tcp/ip connections,
 * but does not support most VMS systems. */
#if !defined(VMS) || defined(UCX)
# define SLRN_USE_SLTCP		1
#else
# define SLRN_USE_SLTCP		0
#endif
/* You may want to chose a smaller number when using a dialup connection
 * with a dynamical IP address; however, do not make it too small to avoid
 * unnecessary re-connects! */
#define SLRN_SLTCP_TIMEOUT_SECS 120

#ifndef VMS
# define SLRN_HAS_DECODE	1
# define SLRN_HAS_PIPING	1
#else
# define SLRN_HAS_PIPING	0
# define SLRN_HAS_DECODE	0
#endif

/* If non-zero, an rn style lock file will be created if .newsrc is the newsrc
 * file.
 */
#if defined(VMS) || defined(__os2__) || defined(__NT__)
# define SLRN_HAS_RNLOCK	0
#else
# define SLRN_HAS_RNLOCK	1
#endif

/* Number of messages slrnpull requests in a row to reduce the time it spends
 * waiting for the server's response.  If your connection drops a lot and you
 * are mainly downloading large messages, you might want to reduce this.
 */
#define SLRN_MAX_QUEUED	10

#define SLRN_MAX_DISPLAY_FORMATS 10

/* ----------------  LOCAL SPOOL and INEWS filenames and configuration ----------------------- */

#if SLRN_HAS_INEWS_SUPPORT && ! defined(SLRN_INEWS_COMMAND)
  /* Note the -S flag.  slrn appends the signature to the file to be posted and
   * the -S flag tells inews not to also do this.  The -h flag must be used. */

  /* Changing this here has no effect when using ./configure (on Unix) */
# define SLRN_INEWS_COMMAND      "/usr/local/bin/inews -S -h"
#endif

#if SLRN_HAS_SPOOL_SUPPORT || defined(SLRNPULL_CODE)

/* Note: Do not be confused by INN.  You do not need INN.  slrn can work with
 *       CNEWS just as well.
 */

  /* Root directory names */
# define SLRN_SPOOL_ROOT	"/var/spool/news"
  /* SLRN_NOV_ROOT gives the root directory for overview files
   * if you don't have overview files, leave as SLRN_SPOOL_ROOT for now */
# define SLRN_SPOOL_NOV_ROOT	SLRN_SPOOL_ROOT
  /* SLRN_NOV_FILE gives filename for overview file in each directory */
# define SLRN_SPOOL_NOV_FILE	".overview"
# define SLRN_SPOOL_HEADERS	".headers"

# define SLRN_SPOOL_INNROOT	"/var/lib/news"
  /* If the following filenames are relative ones, they are considered to be
   * relative to SLRN_SPOOL_INNROOT.
   */
# define SLRN_SPOOL_ACTIVE	"data/active"
# define SLRN_SPOOL_ACTIVETIMES	"data/active.times"
# define SLRN_SPOOL_NEWSGROUPS	"data/newsgroups"
# define SLRN_SPOOL_OVERVIEWFMT "data/overview.fmt"

  /* set to 1 to allow scanning the active file for article ranges if there's
   * no .overview file -- if 0 or no active file, then look at filenames in
   * the spool directory instead.  0 seems best... */
# define SPOOL_ACTIVE_FOR_ART_RANGE 0
#endif

/* ---------------- end of INEWS and LOCAL SPOOL configuration ----------- */

#ifdef VMS
/* 
 *                                                            VMS filenames
 */
# define SLRN_FAILED_POST_FILE		"slrn-failed-post.txt"
# define SLRN_USER_SLRNRC_FILENAME	"slrn.rc"
# define SLRN_LETTER_FILENAME		"slrn-letter.txt"
# define SLRN_ARTICLE_FILENAME		"slrn-article.txt"
# define SLRN_FOLLOWUP_FILENAME		"slrn-followup.txt"
# define SLRN_SIGNATURE_FILE		".signature"
# ifndef SYSCONFDIR
#  define SYSCONFDIR			"sys$manager:"
# endif
# ifndef SHAREDIR
#  define SHAREDIR			"sys$manager:"
# endif
#else
# if defined(IBMPC_SYSTEM)
/*
 *                                                             OS/2 filenames
 */
#  define SLRN_FAILED_POST_FILE		"failpost.txt"
#  define SLRN_USER_SLRNRC_FILENAME	"slrn.rc"
#  define SLRN_LETTER_FILENAME		"letter.txt"
#  define SLRN_ARTICLE_FILENAME		"article.txt"
#  define SLRN_FOLLOWUP_FILENAME	"followup.txt"
#  define SLRN_SIGNATURE_FILE		"signatur.txt"
#  define SLRN_SENDMAIL_COMMAND		"sendmail -t -af"
#  ifndef SYSCONFDIR
#    define SYSCONFDIR			"C:/slrn"
#  endif
#  ifndef SHAREDIR
#    define SHAREDIR			"C:/slrn"
#  endif
#  ifndef SLRN_LIB_DIR
#    define SLRN_LIB_DIR		"C:/slrn"
#  endif
# else
#  ifdef __unix__
/* 
 *                                                             Unix filenames
 */
#   define SLRN_FAILED_POST_FILE	"slrn-failed-post.txt"
#   define SLRN_USER_SLRNRC_FILENAME	".slrnrc"
#   define SLRN_LETTER_FILENAME	".letter"
#   define SLRN_ARTICLE_FILENAME	".article"
#   define SLRN_FOLLOWUP_FILENAME	".followup"
#   define SLRN_SIGNATURE_FILE		".signature"
  /* Changing these here has no effect when using ./configure */
#   ifndef SLRN_SENDMAIL_COMMAND
#    define SLRN_SENDMAIL_COMMAND	"/usr/lib/sendmail -oi -t -oem -odb"
#   endif
#  endif			       /* unix */
# endif				       /* os2 */
#endif				       /* vms */

/* #define OUR_ORGANIZATION "organization-name" */
/* #define OUR_HOSTNAME "host.name.here" */

#if SLRN_HAS_GROUPLENS
# undef SLRN_USE_SLTCP
# define SLRN_USE_SLTCP 1
#endif

/* The rest of the files apply to slrnpull. */

/* This must be set to an absolute pathname. */
#define SLRNPULL_ROOT_DIR	"/var/spool/news/slrnpull"

/* The remaing variables are specified as relative names with respect to the
 * SLRNPULL_ROOT_DIR.
 */

/* slrnpull configuration filename. */
#define SLRNPULL_CONF		"slrnpull.conf"

/* slrnpull outgoing post directory. */
#define SLRNPULL_OUTGOING_DIR	"out.going"

/* slrnpull failed outgoing post directory. */
#define SLRNPULL_OUTGOING_BAD_DIR	"rejects"

/* slrnpull requested bodies directory. */
#define SLRNPULL_REQUESTS_DIR	"requests"

/* The file that will be used for killing articles as they are fetched. */
#define SLRNPULL_SCORE_FILE	"score"

/* All news article retrived from the server will be placed in newsgroup
 * subdirectories in this directory.
 */
#define SLRNPULL_NEWS_DIR	"news"

/* File where messages and errors will be placed. */
#define SLRNPULL_LOGFILE	"log"

#if !SLRN_HAS_NNTP_SUPPORT
# undef SLRN_HAS_GROUPLENS
# define SLRN_HAS_GROUPLENS 0
#endif

/* For the internationalisation using gettext                *
 * This allow to write _("text") instead of gettext("text")  */

#ifdef ENABLE_NLS
# include <libintl.h>
# define _(a) (gettext (a))
# ifdef gettext_noop
#  define N_(a) gettext_noop (a)
# else
#  define N_(a) (a)
# endif
#else
# define _(a) (a)
# define N_(a) a
#endif

/* Default startup mode, selected automatically. Do not modify.
 */
#if SLRN_HAS_NNTP_SUPPORT
# define SLRN_DEFAULT_SERVER_OBJ	SLRN_SERVER_ID_NNTP
# define SLRN_DEFAULT_POST_OBJ		SLRN_POST_ID_NNTP
#else
# define SLRN_DEFAULT_SERVER_OBJ	SLRN_SERVER_ID_SPOOL
# define SLRN_DEFAULT_POST_OBJ		SLRN_POST_ID_INEWS
#endif

#if SLRN_HAS_INEWS_SUPPORT && SLRN_FORCE_INEWS
# undef SLRN_DEFAULT_POST_OBJ
# define SLRN_DEFAULT_POST_OBJ SLRN_POST_ID_INEWS
#endif

#endif				       /* _SLRN_FEATURES_H */
