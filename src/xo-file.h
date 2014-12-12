/*
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of  
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef XO_FILE_H
#define XO_FILE_H

#define DEFAULT_SHORTEN_MENUS \
  "optionsProgressiveBG optionsLeftHanded optionsButtonSwitchMapping"

#define GS_CMDLINE \
  "gs -sDEVICE=bmp16m -r%f -q -sOutputFile=- " \
  "-dNOPAUSE -dBATCH -dEPSCrop -dTextAlphaBits=4 -dGraphicsAlphaBits=4 %s"

extern int GS_BITMAP_DPI, PDFTOPPM_PRINTING_DPI;

#define AUTOSAVE_MAX 9
#define AUTOSAVE_FILENAME_TEMPLATE "%s.autosave%d.xoj"
#define AUTOSAVE_FILENAME_FILTER "%s.autosave*.xoj"

void new_journal(void);
gboolean save_journal(const char *filename, gboolean is_auto);
gboolean close_journal(void);
gboolean open_journal(char *filename);

struct Background *attempt_load_pix_bg(char *filename, gboolean attach);
GList *attempt_load_gv_bg(char *filename);
struct Background *attempt_screenshot_bg(void);

void cancel_bgpdf_request(struct BgPdfRequest *req);
gboolean add_bgpdf_request(int pageno, double zoom);
gboolean bgpdf_scheduler_callback(gpointer data);
void shutdown_bgpdf(void);
gboolean init_bgpdf(char *pdfname, gboolean create_pages, int file_domain);

void bgpdf_create_page_with_bg(int pageno, struct BgPdfPage *bgpg);
void bgpdf_update_bg(int pageno, struct BgPdfPage *bgpg);


void init_config_default(void);
void load_config_from_file(void);
void save_config_to_file(void);

void autosave_cleanup(GList **list);
void init_autosave(void);
gboolean autosave_cb(gpointer is_catchup);
char *check_for_autosave(char *filename);
void journal_metadata_page_save(char *filename, int pageno);
#endif
