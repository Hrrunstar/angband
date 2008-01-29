#ifndef INCLUDED_OBJECT_H
#define INCLUDED_OBJECT_H


/*** Variables ***/

/* object1.c */

#define MAX_TITLES     50       /* Used with scrolls (min 48) */

/* The titles of scrolls, by sval. */
extern char scroll_adj[MAX_TITLES][16];


/*** Functions ***/

/* object1.c */
void flavor_init(void);
void reset_visuals(bool unused);
void object_flags(const object_type *o_ptr, u32b *f1, u32b *f2, u32b *f3);
void object_flags_known(const object_type *o_ptr, u32b *f1, u32b *f2, u32b *f3);
char index_to_label(int i);
s16b label_to_inven(int c);
s16b label_to_equip(int c);
s16b wield_slot(const object_type *o_ptr);
const char *mention_use(int i);
const char *describe_use(int i);
bool item_tester_okay(const object_type *o_ptr);
int scan_floor(int *items, int max_size, int y, int x, int mode);
void display_inven(void);
void display_equip(void);
void show_inven(void);
void show_equip(void);
void show_floor(const int *floor_list, int floor_num, bool gold);
bool verify_item(const char *prompt, int item);
bool get_item(int *cp, const char *pmt, const char *str, int mode);

/* object2.c */
void excise_object_idx(int o_idx);
void delete_object_idx(int o_idx);
void delete_object(int y, int x);
void compact_objects(int size);
void wipe_o_list(void);
s16b o_pop(void);
object_type *get_first_object(int y, int x);
object_type *get_next_object(const object_type *o_ptr);
void object_known(object_type *o_ptr);
void object_aware(object_type *o_ptr);
void object_tried(object_type *o_ptr);
bool is_blessed(const object_type *o_ptr);
s32b object_value(const object_type *o_ptr);
bool object_similar(const object_type *o_ptr, const object_type *j_ptr);
void object_absorb(object_type *o_ptr, const object_type *j_ptr);
s16b lookup_kind(int tval, int sval);
void object_wipe(object_type *o_ptr);
void object_copy(object_type *o_ptr, const object_type *j_ptr);
void object_prep(object_type *o_ptr, int k_idx);
s16b floor_carry(int y, int x, object_type *j_ptr);
void drop_near(object_type *j_ptr, int chance, int y, int x);
void acquirement(int y1, int x1, int level, int num, bool great);
void place_object(int y, int x, int level, bool good, bool great);
void place_gold(int y, int x, int level);
void place_secret_door(int y, int x);
void place_closed_door(int y, int x);
void place_random_door(int y, int x);
void inven_item_charges(int item);
void inven_item_describe(int item);
void inven_item_increase(int item, int num);
void inven_item_optimize(int item);
void floor_item_charges(int item);
void floor_item_describe(int item);
void floor_item_increase(int item, int num);
void floor_item_optimize(int item);
bool inven_carry_okay(const object_type *o_ptr);
bool inven_stack_okay(const object_type *o_ptr);
s16b inven_carry(object_type *o_ptr);
s16b inven_takeoff(int item, int amt);
void inven_drop(int item, int amt);
void combine_pack(void);
void reorder_pack(void);
void distribute_charges(object_type *o_ptr, object_type *q_ptr, int amt);
void reduce_charges(object_type *o_ptr, int amt);


/*** obj-name.c ***/

/**
 * Modes for object_desc().
 */
enum
{
	ODESC_BASE = 0,
	ODESC_COMBAT = 1,
	ODESC_FULL = 3,
	ODESC_STORE = 4
};

/**
 * Describes item "o_ptr" into buffer "buf" of size "max".
 *
 * If "prefix" is TRUE, then the name will be prefixed with a pseudo-numeric
 * indicator of the number of items in the pile.
 *
 * Modes ("prefix" is TRUE):
 *   OD_BASE   -- Chain Mail of Death
 *   OD_COMBAT -- Chain Mail of Death [1,+3]
 *   OD_STORE  -- 5 Rings of Death [1,+3] (+2 to Stealth) {nifty}
 *   OD_fULL   -- 5 Rings of Death [1,+3] (+2 to Stealth) {nifty} (squelch)
 *
 * Modes ("prefix" is FALSE):
 *   OD_BASE   -- Chain Mail of Death
 *   OD_COMBAT -- Chain Mail of Death [1,+3]
 *   OD_STORE  -- Rings of Death [1,+3] (+2 to Stealth) {nifty}
 *   OD_FULL   -- Rings of Death [1,+3] (+2 to Stealth) {nifty} (squelch)
 */
size_t object_desc(char *buf, size_t max, const object_type *o_ptr, bool prefix, int mode);

/**
 * Describes item "o_ptr" fully into buffer "buf" of size "max".
 *
 * This differs from object_desc() only in that it can provide information the
 * player isn't meant to know.
 */
void object_desc_spoil(char *buf, size_t max, const object_type *o_ptr, int pref, int mode);

/**
 * Describe item kind "k_idx" into buffer "buf" of size "max".
 *
 * XXX
 */
void object_kind_name(char *buf, size_t max, int k_idx, bool easy_know);


/* obj-make.c */
void free_obj_alloc(void);
bool init_obj_alloc(void);
s16b get_obj_num(int level);
void apply_magic(object_type *o_ptr, int lev, bool okay, bool good, bool great);
bool make_object(object_type *j_ptr, int lev, bool good, bool great);
bool make_gold(object_type *j_ptr, int lev);

/* obj-info.c */
void object_info_header(const object_type *o_ptr);
bool object_info_known(const object_type *o_ptr);
bool object_info_full(const object_type *o_ptr);
bool object_info_store(const object_type *o_ptr);

#endif /* !INCLUDED_OBJECT_H */