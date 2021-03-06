#pragma once

#include <algorithm>

#include "execution/sql/value.h"

namespace terrier::execution::sql {

/**
 * Comparison functions for SQL values.
 */
class EXPORT ComparisonFunctions {
 public:
  // Delete to force only static functions
  ComparisonFunctions() = delete;

  /**
   * Sets result = (v1 == v2)
   */
  static void EqBoolVal(BoolVal *result, const BoolVal &v1, const BoolVal &v2);

  /**
   * Sets result = (v1 >= v2)
   */
  static void GeBoolVal(BoolVal *result, const BoolVal &v1, const BoolVal &v2);

  /**
   * Sets result = (v1 > v2)
   */
  static void GtBoolVal(BoolVal *result, const BoolVal &v1, const BoolVal &v2);

  /**
   * Sets result = (v1 <= v2)
   */
  static void LeBoolVal(BoolVal *result, const BoolVal &v1, const BoolVal &v2);

  /**
   * Sets result = (v1 < v2)
   */
  static void LtBoolVal(BoolVal *result, const BoolVal &v1, const BoolVal &v2);

  /**
   * Sets result = (v1 != v2)
   */
  static void NeBoolVal(BoolVal *result, const BoolVal &v1, const BoolVal &v2);

  /**
   * Sets result = (v1 == v2)
   */
  static void EqInteger(BoolVal *result, const Integer &v1, const Integer &v2);

  /**
   * Sets result = (v1 >= v2)
   */
  static void GeInteger(BoolVal *result, const Integer &v1, const Integer &v2);

  /**
   * Sets result = (v1 > v2)
   */
  static void GtInteger(BoolVal *result, const Integer &v1, const Integer &v2);

  /**
   * Sets result = (v1 <= v2)
   */
  static void LeInteger(BoolVal *result, const Integer &v1, const Integer &v2);

  /**
   * Sets result = (v1 < v2)
   */
  static void LtInteger(BoolVal *result, const Integer &v1, const Integer &v2);

  /**
   * Sets result = (v1 != v2)
   */
  static void NeInteger(BoolVal *result, const Integer &v1, const Integer &v2);

  /**
   * Sets result = (v1 == v2)
   */
  static void EqReal(BoolVal *result, const Real &v1, const Real &v2);

  /**
   * Sets result = (v1 >= v2)
   */
  static void GeReal(BoolVal *result, const Real &v1, const Real &v2);

  /**
   * Sets result = (v1 > v2)
   */
  static void GtReal(BoolVal *result, const Real &v1, const Real &v2);

  /**
   * Sets result = (v1 <= v2)
   */
  static void LeReal(BoolVal *result, const Real &v1, const Real &v2);

  /**
   * Sets result = (v1 < v2)
   */
  static void LtReal(BoolVal *result, const Real &v1, const Real &v2);

  /**
   * Sets result = (v1 != v2)
   */
  static void NeReal(BoolVal *result, const Real &v1, const Real &v2);

  /**
   * Sets result = (v1 == v2)
   */
  static void EqStringVal(BoolVal *result, const StringVal &v1, const StringVal &v2);

  /**
   * Sets result = (v1 >= v2)
   */
  static void GeStringVal(BoolVal *result, const StringVal &v1, const StringVal &v2);

  /**
   * Sets result = (v1 > v2)
   */
  static void GtStringVal(BoolVal *result, const StringVal &v1, const StringVal &v2);

  /**
   * Sets result = (v1 <= v2)
   */
  static void LeStringVal(BoolVal *result, const StringVal &v1, const StringVal &v2);

  /**
   * Sets result = (v1 < v2)
   */
  static void LtStringVal(BoolVal *result, const StringVal &v1, const StringVal &v2);

  /**
   * Sets result = (v1 != v2)
   */
  static void NeStringVal(BoolVal *result, const StringVal &v1, const StringVal &v2);

  /**
   * Sets result = (v1 == v2)
   */
  static void EqDateVal(BoolVal *result, const DateVal &v1, const DateVal &v2);

  /**
   * Sets result = (v1 >= v2)
   */
  static void GeDateVal(BoolVal *result, const DateVal &v1, const DateVal &v2);

  /**
   * Sets result = (v1 > v2)
   */
  static void GtDateVal(BoolVal *result, const DateVal &v1, const DateVal &v2);

  /**
   * Sets result = (v1 <= v2)
   */
  static void LeDateVal(BoolVal *result, const DateVal &v1, const DateVal &v2);

  /**
   * Sets result = (v1 < v2)
   */
  static void LtDateVal(BoolVal *result, const DateVal &v1, const DateVal &v2);

  /**
   * Sets result = (v1 != v2)
   */
  static void NeDateVal(BoolVal *result, const DateVal &v1, const DateVal &v2);

  /**
   * Sets result = (v1 == v2)
   */
  static void EqTimestampVal(BoolVal *result, const TimestampVal &v1, const TimestampVal &v2);

  /**
   * Sets result = (v1 >= v2)
   */
  static void GeTimestampVal(BoolVal *result, const TimestampVal &v1, const TimestampVal &v2);

  /**
   * Sets result = (v1 > v2)
   */
  static void GtTimestampVal(BoolVal *result, const TimestampVal &v1, const TimestampVal &v2);

  /**
   * Sets result = (v1 <= v2)
   */
  static void LeTimestampVal(BoolVal *result, const TimestampVal &v1, const TimestampVal &v2);

  /**
   * Sets result = (v1 < v2)
   */
  static void LtTimestampVal(BoolVal *result, const TimestampVal &v1, const TimestampVal &v2);

  /**
   * Sets result = (v1 != v2)
   */
  static void NeTimestampVal(BoolVal *result, const TimestampVal &v1, const TimestampVal &v2);

  /**
   * Compare two raw strings. Returns:
   * < 0 if s1 < s2
   * 0 if s1 == s2
   * > 0 if s1 > s2
   *
   * @param s1 The first string.
   * @param len1 The length of the first string.
   * @param s2 The second string.
   * @param len2 The length of the second string.
   * @param min_len The minimum length between the two input strings.
   * @return The appropriate signed value indicating comparison order.
   */
  static int32_t RawStringCompare(const char *s1, std::size_t len1, const char *s2, std::size_t len2,
                                  std::size_t min_len) {
    const auto result = (min_len == 0) ? 0 : std::memcmp(s1, s2, min_len);
    if (result != 0) {
      return result;
    }
    return int32_t(len1) - int32_t(len2);
  }

 private:
  /**
   * Compare two strings. Returns
   * < 0 if s1 < s2
   * 0 if s1 == s2
   * > 0 if s1 > s2
   *
   * @param v1 The first string.
   * @param v2 The second string.
   * @return The appropriate signed value indicating comparison order.
   */
  static int32_t Compare(const StringVal &v1, const StringVal &v2) {
    TERRIER_ASSERT(!v1.is_null_ && !v2.is_null_, "Both input strings must not be null");
    const auto min_len = std::min(v1.len_, v2.len_);
    if (min_len == 0) {
      if (v1.len_ == v2.len_) {
        return 0;
      }
      if (v1.len_ == 0) {
        return -1;
      }
      return 1;
    }
    return RawStringCompare(v1.Content(), v1.len_, v2.Content(), v2.len_, min_len);
  }
};

// ---------------------------------------------------------
// Implementation below
// ---------------------------------------------------------

// The functions below are inlined in the header for performance. Don't move it
// unless you know what you're doing.

#define BINARY_COMPARISON_NUMERIC_FN_HIDE_NULL(NAME, TYPE, OP)                                   \
  inline void ComparisonFunctions::NAME##TYPE(BoolVal *result, const TYPE &v1, const TYPE &v2) { \
    result->is_null_ = (v1.is_null_ || v2.is_null_);                                             \
    result->val_ = v1.val_ OP v2.val_;                                                           \
  }

#define BINARY_COMPARISON_STRING_FN_HIDE_NULL(NAME, TYPE, OP)                                    \
  inline void ComparisonFunctions::NAME##TYPE(BoolVal *result, const TYPE &v1, const TYPE &v2) { \
    if (v1.is_null_ || v2.is_null_) {                                                            \
      *result = BoolVal::Null();                                                                 \
      return;                                                                                    \
    }                                                                                            \
    *result = BoolVal(Compare(v1, v2) OP 0);                                                     \
  }

#define BINARY_COMPARISON_ALL_TYPES(NAME, OP)                \
  BINARY_COMPARISON_NUMERIC_FN_HIDE_NULL(NAME, BoolVal, OP)  \
  BINARY_COMPARISON_NUMERIC_FN_HIDE_NULL(NAME, Integer, OP)  \
  BINARY_COMPARISON_NUMERIC_FN_HIDE_NULL(NAME, Real, OP)     \
  BINARY_COMPARISON_STRING_FN_HIDE_NULL(NAME, StringVal, OP) \
  BINARY_COMPARISON_NUMERIC_FN_HIDE_NULL(NAME, DateVal, OP)  \
  BINARY_COMPARISON_NUMERIC_FN_HIDE_NULL(NAME, TimestampVal, OP)

BINARY_COMPARISON_ALL_TYPES(Eq, ==);
BINARY_COMPARISON_ALL_TYPES(Ge, >=);
BINARY_COMPARISON_ALL_TYPES(Gt, >);
BINARY_COMPARISON_ALL_TYPES(Le, <=);
BINARY_COMPARISON_ALL_TYPES(Lt, <);
BINARY_COMPARISON_ALL_TYPES(Ne, !=);

#undef BINARY_COMPARISON_ALL_TYPES
#undef BINARY_COMPARISON_STRING_FN_HIDE_NULL
#undef BINARY_COMPARISON_NUMERIC_FN_HIDE_NULL
#undef BINARY_COMPARISON_DATE_FN_HIDE_NULL
}  // namespace terrier::execution::sql
