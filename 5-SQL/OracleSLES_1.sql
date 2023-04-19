select count (*) from sp.models;

select * from sp.models;

begin
  o( 'poglad kota' );
end;

select name from sp.models;

select * from sp.model_objects;

select * from sp.model_objects where model_id=200;

select count (*) from sp.model_objects where model_id=200;

select MOD_OBJ_ID from SP.MODEL_OBJECT_PAR_S;

select distinct MOD_OBJ_ID from SP.MODEL_OBJECT_PAR_S;

select count (MOD_OBJ_ID) from SP.MODEL_OBJECT_PAR_S;

select distinct count (MOD_OBJ_ID) from SP.MODEL_OBJECT_PAR_S;

select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S group by MOD_OBJ_ID;


select max (N_IDS) from
(
  select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S group by MOD_OBJ_ID
);

select UNIQUE_MOD_OBJ_ID from
(
  select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S group by MOD_OBJ_ID
)
where N_IDS=
(
  select max (N_IDS) from
  (
    select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S group by MOD_OBJ_ID
  )
);


select * from SP.MODEL_OBJECTS where MODEL_ID=200;

select OBJ_ID from SP.MODEL_OBJECTS where MODEL_ID=200;


select UNIQUE_MOD_OBJ_ID from
(
  select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S where MOD_OBJ_ID in
  (
    select OBJ_ID from SP.MODEL_OBJECTS where MODEL_ID=200
  )
  group by MOD_OBJ_ID
)
where N_IDS=
(
  select max (N_IDS) from
  (
    select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S where MOD_OBJ_ID in
    (
      select OBJ_ID from SP.MODEL_OBJECTS where MODEL_ID=200
    )
    group by MOD_OBJ_ID
  )
);


select * from SP.MODEL_OBJECTS where ID=400;

select max (N_IDS) from
  (
    select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S where MOD_OBJ_ID in
    (
      select OBJ_ID from SP.MODEL_OBJECTS where MODEL_ID=200
    )
    group by MOD_OBJ_ID
  )
  
select count (*) from SP.MODEL_OBJECT_PAR_S where MOD_OBJ_ID=336900;

select count (*) from SP.MODEL_OBJECT_PAR_S where MOD_OBJ_ID=400;

select * from SP.MODEL_OBJECTS where ID=400;


select UNIQUE_MOD_OBJ_ID from
(
  select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S where MOD_OBJ_ID in
  (
    select ID from SP.MODEL_OBJECTS where MODEL_ID=200
  )
  group by MOD_OBJ_ID
)
where N_IDS=
(
  select max (N_IDS) from
  (
    select count (MOD_OBJ_ID) n_ids, MOD_OBJ_ID unique_mod_obj_id from SP.MODEL_OBJECT_PAR_S where MOD_OBJ_ID in
    (
      select ID from SP.MODEL_OBJECTS where MODEL_ID=200
    )
    group by MOD_OBJ_ID
  )
);


declare
i number;
begin
  i:=1;
  loop
    o(to_char(i));
    i:=i+1;
    exit when i=100;
  end loop;
end;


begin
  for i in (select distinct MOD_OBJ_ID obj_id from SP.MODEL_OBJECT_PAR_S)
  loop
    o(to_char(i.obj_id));
  end loop;
end;


select level, MOD_OBJ_NAME, (select MOD_OBJ_NAME from SP.MODEL_OBJECTS where ID=PARENT_MOD_OBJ_ID) parent_name, PARENT_MOD_OBJ_ID, ID from
(
  select * from SP.MODEL_OBJECTS where MODEL_ID=200
)
connect by prior PARENT_MOD_OBJ_ID=ID


select level, MOD_OBJ_NAME, (select MOD_OBJ_NAME from SP.MODEL_OBJECTS where ID=PARENT_MOD_OBJ_ID) parent_name, ID, PARENT_MOD_OBJ_ID from
(
  select * from SP.MODEL_OBJECTS where MODEL_ID=200
)
start with ID=500
connect by PARENT_MOD_OBJ_ID=prior ID
