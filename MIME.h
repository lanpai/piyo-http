#ifndef __MIME_H
#define __MIME_H

#include <map>
#include <string>

#include "Message.h"

std::map<std::string, std::string> MIME_TYPES = {
    {   "atom",     "application/atom+xml"                  },
    {   "ear",      "application/java-archive"              },
    {   "jar",      "application/java-archive"              },
    {   "war",      "application/java-archive"              },
    {   "js",       "application/javascript"                },
    {   "jsonp",    "application/javascript"                },
    {   "json",     "application/json"                      },
    {   "hqx",      "application/mac-binhex40"              },
    {   "doc",      "application/msword"                    },
    {   "pdf",      "application/pdf"                       },
    {   "ai",       "application/postscript"                },
    {   "eps",      "application/postscript"                },
    {   "ps",       "application/postscript"                },
    {   "rtf",      "application/rtf"                       },
    {   "rss",      "application/rss+xml"                   },
    {   "xls",      "application/vnd.ms-excel"              },
    {   "eot",      "application/vnd.ms-fontobject"         },
    {   "ppt",      "application/vnd.ms-powerpoint"         },
    {   "odg",      "application/vnd.oasis.opendocument.graphics"                               },
    {   "odp",      "application/vnd.oasis.opendocument.presentation"                           },
    {   "ods",      "application/vnd.oasis.opendocument.spreadsheet"                            },
    {   "odt",      "application/vnd.oasis.opendocument.text"                                   },
    {   "pptx",     "application/vnd.openxmlformats-officedocument.presentationml.presentation" },
    {   "xlsx",     "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"         },
    {   "docx",     "application/vnd.openxmlformats-officedocument.wordprocessingml.document"   },
    {   "wmlc",     "application/vnd.wap.wmlc"              },
    {   "7z",       "application/x-7z-compressed"           },
    {   "crx",      "application/x-chrome-extension"        },
    {   "cco",      "application/x-cocoa"                   },
    {   "jardiff",  "application/x-java-archive-diff"       },
    {   "jnlp",     "application/x-java-jnlp-file"          },
    {   "run",      "application/x-makeself"                },
    {   "pl",       "application/x-perl"                    },
    {   "pm",       "application/x-perl"                    },
    {   "pdb",      "application/x-pilot"                   },
    {   "prc",      "application/x-pilot"                   },
    {   "rar",      "application/x-rar-compressed"          },
    {   "rpm",      "application/x-redhat-package-manager"  },
    {   "sea",      "application/x-sea"                     },
    {   "swf",      "application/x-shockwave-flash"         },
    {   "sit",      "application/x-stuffit"                 },
    {   "tcl",      "application/x-tcl"                     },
    {   "tk",       "application/x-tcl"                     },
    {   "webapp",   "application/x-web-app-manifest+json"   },
    {   "crt",      "application/x-x509-ca-cert"            },
    {   "det",      "application/x-x509-ca-cert"            },
    {   "pem",      "application/x-x509-ca-cert"            },
    {   "xpi",      "application/x-xpinstall"               },
    {   "xhtml",    "application/xhtml+xml"                 },
    {   "xml",      "application/xml"                       },
    {   "rdf",      "application/xml"                       },
    {   "xspf",     "application/xspf+xml"                  },
    {   "zip",      "application/zip"                       },

    {   "m4a",      "audio/m4a"                             },
    {   "kar",      "audio/midi"                            },
    {   "mid",      "audio/midi"                            },
    {   "midi",     "audio/midi"                            },
    {   "f4a",      "audio/mp4"                             },
    {   "f4b",      "audio/mp4"                             },
    {   "mp3",      "audio/mpeg"                            },
    {   "ogg",      "audio/ogg"                             },
    {   "oga",      "audio/ogg"                             },
    {   "ra",       "audio/x-realaudio"                     },

    {   "otf",      "font/opentype"                         },
    {   "woff",     "font/woff"                             },
    {   "woff2",    "font/woff2"                            },

    {   "gif",      "image/gif"                             },
    {   "jpeg",     "image/jpeg"                            },
    {   "jpg",      "image/jpeg"                            },
    {   "png",      "image/png"                             },
    {   "svg",      "image/svg+xml"                         },
    {   "svgz",     "image/svg+xml"                         },
    {   "tif",      "image/tiff"                            },
    {   "tiff",     "image/tiff"                            },
    {   "wbmp",     "image/vnd.wap.wbmp"                    },
    {   "webp",     "image/webp"                            },
    {   "ico",      "image/x-icon"                          },
    {   "jng",      "image/x-jng"                           },
    {   "bmp",      "image/x-ms-bmp"                        },

    {   "appcache", "text/cache-manifest"                   },
    {   "manifest", "text/cache-manifest"                   },
    {   "css",      "text/css"                              },
    {   "htm",      "text/html"                             },
    {   "html",     "text/html"                             },
    {   "shtml",    "text/html"                             },
    {   "txt",      "text/plain"                            },
    {   "mml",      "text/mathml"                           },
    {   "vcf",      "text/v-card"                           },
    {   "jad",      "text/vnd.sun.j2me.app-descriptor"      },
    {   "wml",      "text/vnd.wap.wml"                      },
    {   "vtt",      "text/vtt"                              },
    {   "htc",      "text/x-component"                      },
    {   "xml",      "text/xml"                              },

    {   "3gp",      "video/3gpp"                            },
    {   "3gpp",     "video/3gpp"                            },
    {   "ts",       "video/mp2t"                            },
    {   "f4p",      "video/mp4"                             },
    {   "f4v",      "video/mp4"                             },
    {   "mp4",      "video/mp4"                             },
    {   "mpeg",     "video/mpeg"                            },
    {   "mpg",      "video/mpeg"                            },
    {   "ogv",      "video/ogg"                             },
    {   "mov",      "video/quicktime"                       },
    {   "webm",     "video/webm"                            },
    {   "flv",      "video/x-flv"                           },
    {   "m4v",      "video/x-m4v"                           },
    {   "mng",      "video/x-mng"                           },
    {   "asf",      "video/x-ms-asf"                        },
    {   "asx",      "video/x-ms-asf"                        },
    {   "wmv",      "video/x-ms-wmv"                        },
    {   "avi",      "video/x-msvideo"                       },

    {   "ttc",      "x-font-ttf"                            },
    {   "ttf",      "x-font-ttf"                            }
};

const std::string GetMIME(const std::string &ext) {
    std::map<std::string, std::string>::iterator mime = MIME_TYPES.find(ext);
    if (mime == MIME_TYPES.end())
        return NULL;
    return mime->second;
}

void UpdateMIME(const std::string &ext, Message &message) {
    std::map<std::string, std::string>::iterator mime = MIME_TYPES.find(ext);
    if (mime == MIME_TYPES.end())
        return;
    message.SetHeader("Content-Type", mime->second);
}

#endif
