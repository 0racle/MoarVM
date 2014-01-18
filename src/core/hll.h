/* The configuration for a particular High Level Language. Of note, this
 * indicates the types to use in various situations. */
struct MVMHLLConfig {
    /* The types the language wishes to get things boxed as. */
    MVMObject *int_box_type;
    MVMObject *num_box_type;
    MVMObject *str_box_type;

    /* The type to use for slurpy arrays. */
    MVMObject *slurpy_array_type;

    /* The type to use for slurpy hashes. */
    MVMObject *slurpy_hash_type;

    /* The type to use for array iteration (should have VMIter REPR). */
    MVMObject *array_iterator_type;

    /* The type to use for hash iteration (should have VMIter REPR). */
    MVMObject *hash_iterator_type;

    /* HLL mapping types for cross-HLL boundary for int/num/str. */
    MVMObject *foreign_type_int;
    MVMObject *foreign_type_num;
    MVMObject *foreign_type_str;

    /* HLL mapping transforms for array/hash/code. */
    MVMObject *foreign_transform_array;
    MVMObject *foreign_transform_hash;
    MVMObject *foreign_transform_code;

    /* The value to substitute for null. */
    MVMObject *null_value;

    /* Language's handler to run at a block's exit time, if needed. */
    MVMObject *exit_handler;

    /* Language's handler for bind errors, if needed. */
    MVMObject *bind_error;

    /* Array of types to pass to compiler.c */
    MVMObject *mast_types;

    /* HLL name. */
    MVMString *name;

    /* Inline handle to the hash in which this is stored. */
    UT_hash_handle hash_handle;
};

MVMHLLConfig * MVM_hll_get_config_for(MVMThreadContext *tc, MVMString *name);
MVMObject * MVM_hll_set_config(MVMThreadContext *tc, MVMString *name, MVMObject *config_hash);
MVMHLLConfig * MVM_hll_current(MVMThreadContext *tc);
void MVM_hll_enter_compilee_mode(MVMThreadContext *tc);
void MVM_hll_leave_compilee_mode(MVMThreadContext *tc);
void MVM_hll_map(MVMThreadContext *tc, MVMObject *obj, MVMHLLConfig *hll, MVMRegister *res_reg);
